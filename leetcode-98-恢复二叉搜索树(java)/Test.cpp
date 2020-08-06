二叉搜索树中的两个节点被错误地交换。

请在不改变其结构的情况下，恢复这棵树。

示例 1 :

输入 : [1, 3, null, null, 2]

	1
	/
	3
	\
	2

输出:[3, 1, null, null, 2]

    3
   /
   1
   \
   2


示例 2:

 输入 : [3, 1, 4, null, null, 2]

	    3
	   / \
	  1   4
	 /
	2

 输出:[2, 1, 4, null, null, 3]

	 2
    / \
   1   4
      /
     3


//解题思路
//只是两节点有错，递归找到之后，交换值就行了，也就是一个中序遍历就完事了

/**
* 题目是节点有错
* 不是子树之间有错
*/
	  class Solution {
		  TreeNode x = null, y = null, pred = null;

		  public void findTwoSwapped(TreeNode root)
		  {
			  if (root == null) return;
			  findTwoSwapped(root.left);
			  if (pred != null && root.val < pred.val) 
			  {
				  y = root;
				  if (x == null) x = pred;
				  else return;
			  }
			  pred = root;
			  findTwoSwapped(root.right);
		  }

		  public void recoverTree(TreeNode root) 
		  {
			  findTwoSwapped(root);
			  int tmp = x.val;
			  x.val = y.val;
			  y.val = tmp;
		  }
	  }