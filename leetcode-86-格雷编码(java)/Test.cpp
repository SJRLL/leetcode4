格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异。

给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。即使有多个不同答案，你也只需要返回其中一种。

格雷编码序列必须以 0 开头。

示例 1:
输入 : 2
输出 : [0, 1, 3, 2]
 解释 :
	00 - 0
	01 - 1
	11 - 3
	10 - 2

	对于给定的 n，其格雷编码序列并不唯一。
	例如，[0, 2, 3, 1] 也是一个有效的格雷编码序列。

	00 - 0
	10 - 2
	11 - 3
	01 - 1

示例 2:
 输入 : 0
 输出 : [0]
 解释 : 我们定义格雷编码序列必须以 0 开头。
	   给定编码总位数为 n 的格雷编码序列，其长度为 2n。当 n = 0 时，长度为 20 = 1。
	   因此，当 n = 0 时，其格雷编码序列为[0]。

//解题思路
//递归思路，n = 2 时格雷序列为 00、01、11、10。则 n = 3 时就在其前面顺序加上 0 变为 000、001、011、010，
//仍然符合各类序列，然后再倒序加上 1 变为 110、111、101、100。将这两组合起来就变成了 000、001、011、010、110、111、101、100，
//就得到了 n = 3时的格雷序列。

import java.util.LinkedList;
	  import java.util.List;

	  class Solution {
		  public List<Integer> grayCode(int n) 
		  {
			  return backtrack(n);
		  }

		  private List<Integer> backtrack(int index)
		  {
			  if (index == 0) 
			  {
				  List<Integer> list = new LinkedList<>();
				  list.add(0);
				  return list;
			  }

			  List<Integer> list = backtrack(index - 1);
			  int originLen = list.size();
			  int currentPow = 1 << (index - 1);
			  for (int i = originLen - 1; i >= 0; i--) 
			  {
				  list.add(list.get(i) + currentPow);
			  }
			  return list;
		  }
	  }
