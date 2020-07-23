给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

有效的 IP 地址正好由四个整数（每个整数位于 0 到 255 之间组成），整数之间用 '.' 分隔。



示例 :
输入 : "25525511135"
输出 : ["255.255.11.135", "255.255.111.35"]

//解题思路：
//1、将IP地址的每一段封装成Segment
//2、对每段的1~3位取值进行入栈
//3、根据上一段的取值坐标，创建新段（重要：要将上一段的值保存到新的段中）
//4、判断4段是否完整，并且把所有的字符用完，符合条件的加到结果集中
//5、根据IP地址的合法性进行剪枝

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
			// 在有效数值之外的不合法。
			if (Integer.parseInt(val) > 255 || Integer.parseInt(val) < 0) 
			{
				return false;
			}

			// 以零开始的不合法；
			if (this.val.length() > 1 && this.val.charAt(0) == '0') 
			{
				return false;
			}

			return true;
		}
	}
}
