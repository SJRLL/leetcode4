给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。



示例：
二叉树：[3, 9, 20, null, null, 15, 7],

3
/ \
9  20
/ \
15   7
返回其层次遍历结果：

[
	[3],
	[9, 20],
	[15, 7]
]

//解题思路：
//用队列实现二叉树的广度优先遍历
//1.初始化一个队列，将树的根节点放入队列当中；
//2.对队列进行poll操作，得到新的root，如果此时的root有左孩子，则将左孩子放入队列中，如果有右孩子，则将右孩子放入队列中；
//3.重复步骤 2 ，直到queue为空。

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
	public List<List<Integer>> levelOrder(TreeNode root) 
	{
		List<List<Integer>> res = new ArrayList<>();
		Queue<TreeNode> queue = new LinkedList<>();
		if (root != null)
			queue.add(root);
		while (!queue.isEmpty())
		{
			int n = queue.size();//root不为空时，此时第一层的节点数是n=1；
			List<Integer> list = new ArrayList<>();
			/*再进行n次循环，确保当前层的节点全部出队列，
			并把所有当前层节点的左右孩子加入队列，
			保证队列的size就是下一层的节点数。
			*/
			for (int i = 0; i < n; i++)
			{
				root = queue.poll();
				list.add(root.val);
				if (root.left != null)
					queue.add(root.left);
				if (root.right != null)
					queue.add(root.right);
			}
			res.add(list);
		}
		return res;
	}
}
