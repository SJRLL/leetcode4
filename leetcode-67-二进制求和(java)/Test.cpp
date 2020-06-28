给你两个二进制字符串，返回它们的和（用二进制表示）。

输入为 非空 字符串且只包含数字 1 和 0。

示例 1 :
输入 : a = "11", b = "1"
输出 : "100"

示例 2 :
输入 : a = "1010", b = "1011"
输出 : "10101"

//解题思路
//1、字符串截取，注意字符串长度  2、进行简单位运算

class Solution {
	public String addBinary(String a, String b) 
	{
		int index1 = a.length() - 1;
		int index2 = b.length() - 1;
		StringBuilder builder = new StringBuilder();
		int temp = 0;
		int a1;
		int b1;
		while (index1 >= 0 || index2 >= 0)
		{
			//a上的字符
			a1 = index1 >= 0 ? a.charAt(index1--) - '0' : 0;

			//b上的字符
			b1 = index2 >= 0 ? b.charAt(index2--) - '0' : 0;

			//a1 ^ b1 ^ temp 求出当前位置的结果，逢2进1
			builder.append(a1 ^ b1 ^ temp);

			//进位
			temp = (a1 + b1 + temp) >> 1;
		}
		if (temp > 0){
			builder.append(temp);
		}
		return builder.reverse().toString();
	}
}

