����һ�������������㷵���䰴 ������� �õ��Ľڵ�ֵ�� �������أ������ҷ������нڵ㣩��



ʾ����
��������[3, 9, 20, null, null, 15, 7],

3
/ \
9  20
/ \
15   7
�������α��������

[
	[3],
	[9, 20],
	[15, 7]
]

//����˼·��
//�ö���ʵ�ֶ������Ĺ�����ȱ���
//1.��ʼ��һ�����У������ĸ��ڵ������е��У�
//2.�Զ��н���poll�������õ��µ�root�������ʱ��root�����ӣ������ӷ�������У�������Һ��ӣ����Һ��ӷ�������У�
//3.�ظ����� 2 ��ֱ��queueΪ�ա�

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
			int n = queue.size();//root��Ϊ��ʱ����ʱ��һ��Ľڵ�����n=1��
			List<Integer> list = new ArrayList<>();
			/*�ٽ���n��ѭ����ȷ����ǰ��Ľڵ�ȫ�������У�
			�������е�ǰ��ڵ�����Һ��Ӽ�����У�
			��֤���е�size������һ��Ľڵ�����
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
