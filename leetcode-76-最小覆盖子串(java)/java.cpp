����һ���ַ��� S��һ���ַ��� T�������ַ��� S �����ҳ������� T �����ַ�����С�Ӵ���

ʾ����

���� : S = "ADOBECODEBANC", T = "ABC"
 ��� : "BANC"

//����˼·��
//����Ŀ��һ���������ڵ���Ŀ���ٷ�������� weiwei ���е���Ƶ�����Ѿ�ʮ�������ˡ�
//�ṩһ�ֽ���һ���ַ������¼Ҫƥ���ַ�����Ƶ���ķ�������ϸע�Ͷ��ڴ�����~~Ҳ�ǱȽϺ�����

class Solution {
	public String minWindow(String s, String t) {
		if (s == null || t == null || s.length() == 0 || t.length() == 0) return "";
		// ����һ�����֣�������¼�ַ��� t �г����ַ���Ƶ�ʣ�Ҳ���Ǵ�������Ҫƥ����ַ�����Ӧ��Ƶ��
		int[] map = new int[128];
		for (char c : t.toCharArray()) {
			map[c]++;
		}
		int left = 0, right = 0;
		int match = 0;  // ƥ���ַ��ĸ���
		int minLen = s.length() + 1;   // �����Ӵ��ĳ���
		// �Ӵ�����ʼλ�� �Ӵ�������λ��(����������������Ӵ��Ļ���start��end ���� 0��s.substring ��ȡ���� ����
		int start = 0, end = 0;
		while (right < s.length()){
			char charRight = s.charAt(right); // �ұ߽���Ǹ��ַ�
			map[charRight]--;   // �������Ϊ��Ҫƥ����ַ� charRight ������һ��
			// ����ַ� charRight �� t �д��ڣ���ô������һ�β�����ֻҪ�������ڵ��� 0��˵��ƥ����һ��
			// ���ַ� charRight ���� t �У���ô map[charRight] < 0, �������κβ���
			if (map[charRight] >= 0) match++;
			right++;  // �ұ߽����ƣ���������ͱ���� [)��������㴰�ڴ�С

			// ֻҪ������ƥ����ַ��ﵽ��Ҫ���ұ߽�̶�����߽�����
			while (match == t.length()){
				int size = right - left;
				if (size < minLen){
					minLen = size;
					start = left;
					end = right;
				}
				char charLeft = s.charAt(left);  // ��ߵ��Ǹ��ַ�
				map[charLeft]++;  // ��ߵ��ַ�Ҫ�Ƴ�����
				// ���� t �г��ֵ��ַ����Ƴ����ڣ������ܹ��ﵽ�����ֵ map[charLeft] = 0
				// ���ǡ���Ƴ�����Ҫƥ���һ���ַ�����ô���� map[charLeft] > 0, Ҳ���ǻ�Ҫƥ���ַ� charLeft����ʱ match--
				if (map[charLeft] > 0) match--;
				left++;  // ��߽�����
			}
		}
		return s.substring(start, end);
	}
}
