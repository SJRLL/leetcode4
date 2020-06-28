给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。

你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。

要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。

文本的最后一行应为左对齐，且单词之间不插入额外的空格。

说明 :

单词是指由非空格字符组成的字符序列。
每个单词的长度大于 0，小于等于 maxWidth。
输入单词数组 words 至少包含一个单词。

示例 :

输入 :
	words = ["This", "is", "an", "example", "of", "text", "justification."]
	maxWidth = 16
输出 :
   [
	   "This    is    an",
	   "example  of text",
	   "justification.  "
   ]


示例 2 :
输入 :
   words = ["What", "must", "be", "acknowledgment", "shall", "be"]
   maxWidth = 16
输出 :
   [
	   "What   must   be",
	   "acknowledgment  ",
	   "shall be        "
   ]
 解释 : 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
	 因为最后一行应为左对齐，而不是左右两端对齐。
	 第二行同样为左对齐，这是因为这行只包含一个单词。


 示例 3 :
  输入 :
	  words = ["Science", "is", "what", "we", "understand", "well", "enough", "to", "explain",
	  "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"]
	  maxWidth = 20
  输出 :
	 [
		 "Science  is  what we",
		 "understand      well",
		 "enough to explain to",
		 "a  computer.  Art is",
		 "everything  else  we",
		 "do                  "
	 ]

 class Solution {
		 public List<String> fullJustify(String[] words, int maxWidth) 
		 {
			 List<String> res = new ArrayList<>();
			 int num = 0; //记录当前行目前的数量
			 int bg = 0;
			 for (int i = 0; i < words.length; i++) 
			 {
				 num += words[i].length() + 1; //每次加上1是字符之间至少要空一格。
				 if (i + 1 == words.length || num + words[i + 1].length() > maxWidth) 
				 { //如果到了最后一行，或者改行放不下的情况，那么需要打印结果了
					 boolean isLastLine = i + 1 == words.length; //标记是否到了最后一行
					 res.add(fillwords(words, bg, i, maxWidth, isLastLine));
					 bg = i + 1; //标记起始位置
					 num = 0;
				 }
			 }
			 return res;
		 }

		 public String fillwords(String[] words, int begin, int end, int maxWidth, boolean flag) 
		 { //开始打印啦
			 int wordCount = end - begin + 1;  //字符的数量
			 int spaceCount = maxWidth + 1 - wordCount;
			 for (int i = begin; i <= end; i++) 
			 {
				 spaceCount -= words[i].toString().length();
			 }
			 int spaceSuffix = 1; //至少保证一个空格
			 int spaceAvg = (wordCount == 1 || flag) ? 0 : spaceCount / (wordCount - 1); //平均空格，如果flag为true，就是打印了最后了。
			 int spaceExtra = (wordCount == 1 || flag) ? 0 : spaceCount % (wordCount - 1); //还有多的字符，优先给前面的字符
			 StringBuilder temp = new StringBuilder(); //每一行将字符存入到temp中
			 if (wordCount == 1)
			 { //假如只有一个字符（也可能到了末尾，这种情况也包含在内）
				 int afterCount = maxWidth - words[begin].length() - 1;
				 temp.append(words[begin]);
				 for (int i = 1; i <= (spaceSuffix + spaceAvg + afterCount); i++) 
				 {
					 temp.append(" ");
				 }
			 }
			 else{ //多个字符的情况
				 for (int i = begin; i < end; i++) 
				 {
					 temp.append(words[i]);
					 temp.append(putSpace(spaceSuffix + spaceAvg)); //技术上平均的空格和至少空的一个空格
					 if (spaceExtra != 0) { //额外的空格给放到前面的字符串优先使用。
						 temp.append(" ");
						 spaceExtra--; //记住一定有--操作。
					 }
				 }
				 temp.append(words[end]);
				 if (flag)
				 { //在多个字符串的情况下，如果是到了末尾，将剩下的空格补齐
					 int lastSpace = spaceCount;
					 temp.append(putSpace(lastSpace));
				 }
			 }
			 return temp.toString();

		 }

		 public String putSpace(int n) 
		 { //抽取出来添加n个空格的方法。
			 StringBuilder str = new StringBuilder();
			 for (int i = 1; i <= n; i++) 
			 {
				 str.append(" ");
			 }
			 return str.toString();
		 }
	 }
