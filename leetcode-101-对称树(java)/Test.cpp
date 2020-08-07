给定一个二叉树，检查它是否是镜像对称的。


例如，二叉树 [1, 2, 2, 3, 4, 4, 3] 是对称的。

    1
  /  \
 2    2
/ \  / \
3 4 4   3


但是下面这个 [1, 2, 2, null, 3, null, 3] 则不是镜像对称的:

  1
 / \
2   2
\   \
3    3

//解题思路：
//法一：递归


  class Solution {
	  public boolean isSymmetric(TreeNode root)
	  {
		  if (root == null) 
		  {
			  return true;
		  }
		  return isMirror(root.left, root.right);
	  }
	  private boolean isMirror(TreeNode r1, TreeNode r2)
	  {
		  if (r1 == null && r2 == null) 
		  {
			  return true;
		  }
		  if (r1 == null || r2 == null)
		  {
			  return false;
		  }
		  return (r1.val == r2.val) && isMirror(r1.left, r2.right) && isMirror(r1.right, r2.left);
	  }
  }

 //法二：迭代

  class Solution {
	  public boolean isSymmetric(TreeNode root) 
	  {
		  Queue<TreeNode> queue = new LinkedList<>();
		  queue.offer(root);
		  queue.offer(root);
		  while (!queue.isEmpty()) 
		  {
			  TreeNode r1 = queue.poll();
			  TreeNode r2 = queue.poll();
			  if (r1 == null && r2 == null) 
			  {
				  continue;
			  }
			  if (r1 == null || r2 == null) 
			  {
				  return false;
			  }
			  if (r1.val != r2.val) 
			  {
				  return false;
			  }
			  queue.offer(r1.left);
			  queue.offer(r2.right);
			  queue.offer(r1.right);
			  queue.offer(r2.left);
		  }
		  return true;
	  }
  }
