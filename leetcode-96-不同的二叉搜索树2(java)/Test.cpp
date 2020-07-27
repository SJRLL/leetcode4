给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

示例 :
输入 : 3
输出 : 5
解释 :
给定 n = 3, 一共有 5 种不同结构的二叉搜索树 :

	1         3     3      2      1
	\        /     /      / \      \
	3       2     1      1   3      2
	       /            /     \      \
	       2           1      2       3

//解题思路
//递推法：先算简单的 n<0返回0，n<3返回n；n >= 3时，在是在n<3的基础上构建的，左子树上有0~n - 1个节点，
//对应右子树上有n - 1~0个节点，然后计算组合数并累加即可

	 class Solution {
		 public int numTrees(int n) 
		 {
			 if (n < 0)
			 {
				 return 0;
			 }
			 if (n < 3)
			 {
				 return n;
			 }
			 int[] dp = new int[n + 1];
			 dp[0] = 1;
			 dp[1] = 1;
			 dp[2] = 2;
			 for (int i = 3; i <= n; i++)
			 {
				 for (int j = 0; j < i; j++)
				 {
					 int left = dp[j];
					 int right = dp[i - j - 1];
					 dp[i] += left*right;
				 }
			 }
			 return dp[n];
		 }
	 }
