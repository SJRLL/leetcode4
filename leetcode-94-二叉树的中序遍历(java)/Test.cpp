﻿给定一个二叉树，返回它的中序 遍历。

示例 :

输入 : [1, null, 2, 3]
	1
	\
	2
	/
	3

输出:[1, 3, 2]

//解题思路：1.递归
	 class Solution {
		 public List < Integer > inorderTraversal(TreeNode root) 
		 {
			 List < Integer > res = new ArrayList < >();
			 helper(root, res);
			 return res;
		 }

		 public void helper(TreeNode root, List < Integer > res) 
		 {
			 if (root != null) 
			 {
				 if (root.left != null) 
				 {
					 helper(root.left, res);
				 }
				 res.add(root.val);
				 if (root.right != null) 
				 {
					 helper(root.right, res);
				 }
			 }
		 }
	 }

//解题思路二：栈辅助

	 public class Solution {
		 public List < Integer > inorderTraversal(TreeNode root) 
		 {
			 List < Integer > res = new ArrayList < >();
			 Stack < TreeNode > stack = new Stack < >();
			 TreeNode curr = root;
			 while (curr != null || !stack.isEmpty()) 
			 {
				 while (curr != null)
				 {
					 stack.push(curr);
					 curr = curr.left;
				 }
				 curr = stack.pop();
				 res.add(curr.val);
				 curr = curr.right;
			 }
			 return res;
		 }
	 }
