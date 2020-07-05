给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例 :

输入 : n = 4, k = 2
输出 :
   [
	   [2, 4],
	   [3, 4],
	   [2, 3],
	   [1, 2],
	   [1, 3],
	   [1, 4],
   ]

//解题思路：
//倒着取值，先取n，再取n - 1...最后到1
//剪枝的思路
//当剩下的数字（无论顺着取还是倒着取）小于所要求的个数时，即当要求取2个数字形成一个排列组合时，对于1或者n这种只有一个数字可取的，就没办法形成组合，就可以直接剪去。
//1 在倒着取的时候，使用i < k 作为剪枝条件，测试了一下，速度提升5 - 10倍
//2 顺着取的剪枝思路在注释中

private List<List<Integer>> res;
public List<List<Integer>> combine(int n, int k) 
	 {

		 res = new ArrayList<>();
		 if (k == 0 || n < k)
			 return res;
		 LinkedList<Integer> list = new LinkedList<>();
		 dfs(n, k, list);
		 return res;
	 }

	 private void dfs(int n, int k, LinkedList<Integer> path)
	 {
		 if (k == 0)
		 {
			 res.add(new LinkedList<>(path));
			 return;
		 }

		 for (int i = n; i > 0; i--)
		 {
			 if (i < k)//优化，对于i<k的情况不做处理
				 break;
			 path.addLast(i);
			 dfs(i - 1, k - 1, path);
			 path.removeLast();

		 }
}

