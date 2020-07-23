����һ��ֻ�������ֵ��ַ�������ԭ�����������п��ܵ� IP ��ַ��ʽ��

��Ч�� IP ��ַ�������ĸ�������ÿ������λ�� 0 �� 255 ֮����ɣ�������֮���� '.' �ָ���



ʾ�� :
���� : "25525511135"
��� : ["255.255.11.135", "255.255.111.35"]

//����˼·��
//1����IP��ַ��ÿһ�η�װ��Segment
//2����ÿ�ε�1~3λȡֵ������ջ
//3��������һ�ε�ȡֵ���꣬�����¶Σ���Ҫ��Ҫ����һ�ε�ֵ���浽�µĶ��У�
//4���ж�4���Ƿ����������Ұ����е��ַ����꣬���������ļӵ��������
//5������IP��ַ�ĺϷ��Խ��м�֦

class Solution {
	public List<String> restoreIpAddresses(String s) {
		if (null == s || s.length() < 4) 
		{
			return new ArrayList<>();
		}
		Queue<Segment> queue = new LinkedList<>();
		for (int i = 1; i <= 3; i++) 
		{
			queue.offer(new Segment(s.substring(0, i), 0, 1, i, new StringBuilder()));
		}
		List<String> list = new ArrayList<>();
		while (!queue.isEmpty()) 
		{
			int size = queue.size();

			for (int i = 0; i < size; i++) 
			{
				Segment sg = queue.poll();

				if (!sg.isValid()) 
				{
					continue;
				}
				if (sg.index != 1) 
				{
					sg.sb.append('.');
				}
				sg.sb.append(sg.val);


				if (sg.index == 4) 
				{
					if (sg.sb.length() == s.length() + 3) 
					{
						list.add(sg.sb.toString());
					}

					continue;
				}

				for (int len = 1; len <= 3; len++) {
					int newIndex = sg.index + 1;
					int newStart = sg.start + sg.len;
					if (newStart > s.length() || newStart + len > s.length()) 
					{
						continue;
					}

					String newVal = s.substring(newStart, newStart + len);
					Segment newSg = new Segment(newVal, newStart, newIndex, len, new StringBuilder(sg.sb));
					if (!newSg.isValid()) 
					{
						continue;
					}
					queue.offer(newSg);
				}

			}
		}

		return list;
	}

	private static class Segment 
	{
		private String val;
		private int start;
		private int index;
		private int len;
		private StringBuilder sb;

		public Segment(String val, int start, int index, int len, StringBuilder sb) 
		{
			this.index = index;
			this.len = len;
			this.start = start;
			this.val = val;
			this.sb = sb;
		}

		public boolean isValid() 
		{
			// ����Ч��ֵ֮��Ĳ��Ϸ���
			if (Integer.parseInt(val) > 255 || Integer.parseInt(val) < 0) 
			{
				return false;
			}

			// ���㿪ʼ�Ĳ��Ϸ���
			if (this.val.length() > 1 && this.val.charAt(0) == '0') 
			{
				return false;
			}

			return true;
		}
	}
}
