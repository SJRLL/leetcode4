给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1 :

输入 : 1->2->3->4->5->NULL, k = 2
输出 : 4->5->1->2->3->NULL
 解释 :
向右旋转 1 步 : 5->1->2->3->4->NULL
向右旋转 2 步 : 4->5->1->2->3->NULL
示例 2 :

输入 : 0->1->2->NULL, k = 4
输出 : 2->0->1->NULL
 解释 :
向右旋转 1 步 : 2->0->1->NULL
向右旋转 2 步 : 1->2->0->NULL
向右旋转 3 步 : 0->1->2->NULL
向右旋转 4 步 : 2->0->1->NULL

//解题思路
//先把所有链表节点添加到双端队列中,循环k % deque.size()次，去除多余操作，删除队尾元素插入到队首,重构链表

/**
* Definition for singly-linked list.
* public
*/
class Solution {
	public ListNode rotateRight(ListNode head, int k) {
		if (head == null) 
		{
			return null;
		}
		Deque<ListNode> deque = new LinkedList<>();
		while (head != null) 
		{
			deque.offerLast(head);
			head = head.next;
		}
		for (int i = 0; i < k % deque.size(); i++) 
		{
			deque.offerFirst(deque.pollLast());
		}
		ListNode listNode = new ListNode(0);
		ListNode curr = listNode;
		while (!deque.isEmpty()) 
		{
			curr.next = deque.pollFirst();
			curr = curr.next;
		}
		curr.next = null;
		return listNode.next;
	}
}
