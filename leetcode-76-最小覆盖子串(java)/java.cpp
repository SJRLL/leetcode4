给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字符的最小子串。

示例：

输入 : S = "ADOBECODEBANC", T = "ABC"
 输出 : "BANC"

//解题思路：
//该题目是一个滑动窗口的题目，官方题解里面 weiwei 大佬的视频讲解已经十分清晰了。
//提供一种仅用一个字符数组记录要匹配字符及其频数的方法，详细注释都在代码里~~也是比较好理解的

class Solution {
	public String minWindow(String s, String t) {
		if (s == null || t == null || s.length() == 0 || t.length() == 0) return "";
		// 定义一个数字，用来记录字符串 t 中出现字符的频率，也就是窗口内需要匹配的字符和相应的频率
		int[] map = new int[128];
		for (char c : t.toCharArray()) {
			map[c]++;
		}
		int left = 0, right = 0;
		int match = 0;  // 匹配字符的个数
		int minLen = s.length() + 1;   // 最大的子串的长度
		// 子串的起始位置 子串结束的位置(如果不存在这样的子串的话，start，end 都是 0，s.substring 截取就是 “”
		int start = 0, end = 0;
		while (right < s.length()){
			char charRight = s.charAt(right); // 右边界的那个字符
			map[charRight]--;   // 可以理解为需要匹配的字符 charRight 减少了一个
			// 如果字符 charRight 在 t 中存在，那么经过这一次操作，只要个数大于等于 0，说明匹配了一个
			// 若字符 charRight 不在 t 中，那么 map[charRight] < 0, 不进行任何操作
			if (map[charRight] >= 0) match++;
			right++;  // 右边界右移，这样下面就变成了 [)，方便计算窗口大小

			// 只要窗口内匹配的字符达到了要求，右边界固定，左边界收缩
			while (match == t.length()){
				int size = right - left;
				if (size < minLen){
					minLen = size;
					start = left;
					end = right;
				}
				char charLeft = s.charAt(left);  // 左边的那个字符
				map[charLeft]++;  // 左边的字符要移出窗口
				// 不在 t 中出现的字符，移出窗口，最终能够达到的最大值 map[charLeft] = 0
				// 如果恰好移出了需要匹配的一个字符，那么这里 map[charLeft] > 0, 也就是还要匹配字符 charLeft，此时 match--
				if (map[charLeft] > 0) match--;
				left++;  // 左边界收缩
			}
		}
		return s.substring(start, end);
	}
}
