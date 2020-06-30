给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符


示例 1：

输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse->rorse(将 'h' 替换为 'r')
rorse->rose(删除 'r')
rose->ros(删除 'e')
示例 2：

输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention->inention(删除 't')
inention->enention(将 'i' 替换为 'e')
enention->exention(将 'n' 替换为 'x')
exention->exection(将 'n' 替换为 'c')
exection->execution(插入 'u')

//解题思路：动态规划

class Solution {
    // 动态规划一般都可以写成递归的形式，然后动态规划自底向上走，同时剪枝
    // i,j表示指向字符串具体位置的指针
	public int dp(String word1, String word2, int i, int j){
		if (i == -1) return j + 1;
		if (j == -1) return i + 1;
		if (word1.charAt(i) == word2.charAt(j)) return dp(word1, word2, i - 1, j - 1);
		else{
			// 插入
			// 删除
			// 替换
			return min(dp(word1, word2, i, j - 1) + 1,
				dp(word1, word2, i - 1, j) + 1,
				dp(word1, word2, i - 1, j - 1) + 1);
		}
	}

public int min(int a, int b, int c){
	return Math.min(a, Math.min(b, c));
}
// 二维dp
public int minDistance1(String word1, String word2) {
	int[][] dp = new int[word1.length() + 1][word2.length() + 1];
	for (int j = 0; j <= word2.length(); j++){
		dp[0][j] = j;
	}
	for (int i = 1; i <= word1.length(); i++){
		dp[i][0] = i;
	}
	for (int i = 1; i <= word1.length(); i++){
		for (int j = 1; j <= word2.length(); j++){
			if (word1.charAt(i - 1) == word2.charAt(j - 1)) dp[i][j] = dp[i - 1][j - 1];
			else{
				dp[i][j] = min(dp[i][j - 1] + 1, dp[i - 1][j] + 1, dp[i - 1][j - 1] + 1);
			}
		}
	}
	return dp[word1.length()][word2.length()];
}
// 一维dp
public int minDistance(String word1, String word2) {
	int[] dp = new int[word2.length() + 1];
	for (int j = 1; j <= word2.length(); j++){
		dp[j] = j; // 相当于给dp[0,j]赋值
	}
	for (int i = 1; i <= word1.length(); i++){
		int pre = i - 1;//保存 [i-1,j-1]
		dp[0] = i; // 相当于给dp[i,0]赋值为i
		for (int j = 1; j <= word2.length(); j++){
			int tmp = dp[j];
			if (word1.charAt(i - 1) == word2.charAt(j - 1)) dp[j] = pre;
			else dp[j] = min(dp[j - 1] + 1, dp[j] + 1, pre + 1);
			pre = tmp;
		}
	}
	return dp[word2.length()];
}
}

