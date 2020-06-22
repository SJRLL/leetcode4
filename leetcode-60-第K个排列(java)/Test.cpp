
给出集合[1, 2, 3, …, n]，其所有元素共有 n!种排列。

按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

"123"
"132"
"213"
"231"
"312"
"321"
给定 n 和 k，返回第 k 个排列。

说明：

给定 n 的范围是[1, 9]。
给定 k 的范围是[1, n!]。

示例 1:
输入 : n = 3, k = 3
输出 : "213"

示例 2 :
输入 : n = 4, k = 9
输出 : "2314"

//解题思路：
//从最高位数开始遍历，当第1位保持不变时，剩下的数排列组合有(n - 1)!种，当第2位保持不变时，剩下的数排列组合有(n - 2)!种... 以此类推。
//当k能被某个阶层整除时，说明已经到了这个数字的最后一种排列，剩下的数字倒序就行了。用一个list记录没被用到的数字。

public String getPermutation(int n, int k) {
	StringBuilder sb = new StringBuilder();
	List<Integer> list = new ArrayList<>();
	for (int i = 1; i <= n; i++) list.add(i);

	// 计算 (n-1)!
	int s = 1;
	for (int i = 1; i < n; i++) s *= i;

	while (n > 1) {
		int j = k / s;
		k = k % s;
		s = s / --n;
		if (k == 0) {
			sb.append(list.get(j - 1));
			list.remove(j - 1);
			break;
		}
		else {
			sb.append(list.get(j));
			list.remove(j);
		}
	}

	for (int i = list.size() - 1; i >= 0; i--) {
		sb.append(list.get(i));
	}
	return sb.toString();
}

