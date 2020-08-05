给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。

示例 1 :

输入 :
	 2
	/ \
   1   3
输出: true

示例 2 :

 输入 :
	 5
	/ \
   1   4
  / \
  3  6
输出: false
解释 : 输入为 : [5, 1, 4, null, null, 3, 6]。
	 根节点的值为 5 ，但是其右子节点值为 4 。

//解题思路
//题目需要注意的地方是严格大于和小于 搜索树一般不严格
//中序遍历之后再比较的方法需要完整的遍历一遍再比较时间复杂的更高

//递归思路：
//每个节点带着最大值最小值参加遍历
//在最大值和最小值分别不为null的情况下比较 满足条件节点值严格大于最小值严格小于最大值时递归下一层节点进行比较
//递归下一层节点：左节点的最大值是当前节点值 最小值继承当前节点最小值 右节点最小值为当前节点值最大值继承当前节点最大值
//设置递归返回的条件 flag == false 可以避免在已经确定flase的情况下任然继续遍历


/**
* Definition for a binary tree node.
* public class TreeNode {
*     int val;
*     TreeNode left;
*     TreeNode right;
*     TreeNode(int x) { val = x; }
* }
*/
   class Solution {

	   Boolean flag = true;

	   public boolean isValidBST(TreeNode root) 
	   {
		   helper(root, null, null);
		   return flag;
	   }

	   public void helper(TreeNode root, Integer max, Integer min)
	   {

		   if (flag == false || root == null)
			   return;

		   if ((max != null&&root.val >= max) || (min != null&&root.val <= min))
		   {
			   flag = false;
			   return;
		   }

		   helper(root.left, root.val, min);
		   helper(root.right, max, root.val);

	   }
   }