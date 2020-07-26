给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。



示例：

输入：3
输出：
[
	[1, null, 3, 2],
	[3, 2, null, 1],
	[3, 1, null, null, 2],
	[2, 1, 3],
	[1, null, 2, null, 3]
]
解释：
以上的输出对应以下 5 种不同结构的二叉搜索树：

1         3     3      2      1
\        /     /      / \     \
 3     2     1        1   3     2
      /     /          \         \
     2     1            2         3

//解题思路：
//本题依旧是树的题目，并要求定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树（二叉搜索树：
//树当中的任何子树的左子树的节点都小于根节点，任何子树的右子树的节点都大于根节点）。根据搜索二叉树的定义，
//我们从1~n中取第i个数作为根节点，那么他的前i - 1（从1到i - 1）个数为它的左子树，后n - i（从i + 1到n）个数为它的右子树，
//最后只需将找好的左子树，与 右子树根据排列的方式进行组合即可找出所有的情况。

/**
* Definition for a binary tree node.
* public class TreeNode {
*     int val;
*     TreeNode left;
*     TreeNode right;
*     TreeNode(int x) { val = x; }
* }
*/
import java.util.LinkedList;
class Solution {
	public List<TreeNode> generateTrees(int n) {
		if (n == 0){
			return new LinkedList<TreeNode>();
		}

		return generate_trees(1, n);
	}

	public LinkedList<TreeNode> generate_trees(int start, int end)
	{
		LinkedList<TreeNode> result = new LinkedList<>();
		//如果开始下标start，大于结束下标end，则表示已经没有点了
		if (start > end)
		{
			result.add(null);
			return result;
		}
		for (int i = start; i <= end; i++)
		{
			//找出（start，i-1）个数作为其根节点左子树(二叉搜索树)
			LinkedList<TreeNode> left = generate_trees(start, i - 1);
			//找出（i+1，end）个数作为其根节点右子树(二叉搜索树)
			LinkedList<TreeNode> right = generate_trees(i + 1, end);
			//将左子树与右子树分别与根节点相连
			for (TreeNode k : left)
			{
				for (TreeNode x : right)
				{
					TreeNode node = new TreeNode(i);
					node.left = k;
					node.right = x;
					result.add(node);
				}
			}
		}
		return result;
	}
}
