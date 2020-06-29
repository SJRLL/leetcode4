
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：
输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶

示例 2：
输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶

//解题思路：直接找出数学规律求解

class Solution {

	public static long[][] matrixPower(long[][] x, long[][] y) {
		long a = x[0][0] * y[0][0] + x[0][1] * y[1][0];
		long b = x[0][0] * y[0][1] + x[0][1] * y[1][1];
		long c = x[1][0] * y[0][0] + x[1][1] * y[1][0];
		long d = x[1][0] * y[0][1] + x[1][1] * y[1][1];
		return new long[][]{new long[]{a, b}, new long[]{c, d}};
	}

	public long[][] power2(long[][] x, int y) {
		long[][] res = new long[2][2];
		res[0][0] = 1;
		res[1][1] = 1;
		char[] chars = Integer.toBinaryString(y).toCharArray();
		for (int i = chars.length - 1; i >= 0; i--) {
			if (chars[i] == '1') {
				res = matrixPower(x, res);
			}
			x = matrixPower(x, x);
		}
		return res;
	}

	public int climbStairs(int n) {
		if (n == 1) {
			return 1;
		}
		else if (n == 2) {
			return 2;
		}
		else {
			long[][] x = new long[][]{new long[]{1, 1}, new long[]{1, 0}};
			long[][] temp = power2(x, n - 2);
			long res = 2 * temp[0][0] + temp[1][0];
			return (int)res;
		}
	}
}

