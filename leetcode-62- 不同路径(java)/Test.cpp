一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

问总共有多少条不同的路径？

示例 1
输入 : m = 3, n = 2
输出 : 3
 解释 :
	从左上角开始，总共有 3 条路径可以到达右下角。
	1. 向右->向右->向下
	2. 向右->向下->向右
	3. 向下->向右->向右


示例 2 :
输入 : m = 7, n = 3
输出 : 28

//解题思路
//两种思路：排列组合和动态规划。动态规划比较容易想到，但是空间和时间复杂度都比较高。运用数学的排列组合会比较快得出结果，不需要额外的空间。

class Solution {
	public int uniquePaths(int m, int n) {
		if (m <= 0 || n <= 0) return 0;
		long sum1 = 1;
		long sum2 = 1;
		int numAs = Math.min(m, n) - 1;
		int numBs = m + n - 2;
		for (; numAs >= 1; numAs--, numBs--){
			sum1 *= numBs;
			sum2 *= numAs;
			System.out.println(numBs + "/" + numAs);
		}
		System.out.println(sum1 + "/" + sum2);
		return (int)(sum1 / sum2);
	}
}
