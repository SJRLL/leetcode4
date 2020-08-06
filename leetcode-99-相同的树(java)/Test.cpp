给定两个二叉树，编写一个函数来检验它们是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

示例 1 :

输入 : 1        1
	 / \       / \
	2   3     2   3

	[1, 2, 3], [1, 2, 3]

输出: true

	示例 2 :

输入 : 1          1
	  /           \
	 2             2

	 [1, 2], [1, null, 2]

 输出: false

 示例 3 :

  输入 : 1         1
	    / \       / \
	   2   1     1   2

	   [1, 2, 1], [1, 1, 2]

   输出: false

//解题思路：方法一：递归法，代码非常的短


	   public boolean isSameTree(TreeNode p, TreeNode q) {
		   if (p == null && q == null){
			   return true;
		   }
		   if (p == null || q == null){
			   return false;
		   }
		   if (p.val == q.val){
			   return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
		   }
		   else{
			   return false;
		   }
	   }

//方法二：我一般理解这种方法为手动完成递归
//本质上是一样的，但是内存还是相当的大，我理解的jvm如果是函数递归的内存可能是要比队列大，可是这里却没有差别，刷完题去看看jvm虚拟机吧


		 public boolean isSameTree(TreeNode p, TreeNode q) {
			 Queue<TreeNode> queue = new LinkedList<>();
			 queue.add(p);
			 queue.add(q);
			 while (!queue.isEmpty()){
				 TreeNode t1 = queue.poll();
				 TreeNode t2 = queue.poll();
				 if (t1 == null && t2 == null){
					 continue;
				 }
				 if (t1 == null || t2 == null){
					 return false;
				 }
				 if (t1.val != t2.val){
					 return false;
				 }
				 else {
					 queue.add(t1.left);
					 queue.add(t2.left);
					 queue.add(t1.right);
					 queue.add(t2.right);
				 }
			 }
			 return true;
		 }