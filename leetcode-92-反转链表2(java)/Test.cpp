反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明 :
1 ≤ m ≤ n ≤ 链表长度。

示例 :

输入 : 1->2->3->4->5->NULL, m = 2, n = 4
输出 : 1->4->3->2->5->NULL

//解题思路:
//找到要翻转部分的链表, 将其翻转, 再与原链表拼接

/**
* Definition for singly-linked list.
* public class ListNode {
*     int val;
*     ListNode next;
*     ListNode(int x) { val = x; }
* }
*/
class Solution {
	public ListNode reverseBetween(ListNode head, int m, int n) 
	{
		ListNode dummy = new ListNode(-1);
		dummy.next = head;
		ListNode pre = dummy;
		// 找到翻转链表部分的前一个节点, 1->2->3->4->5->NULL, m = 2, n = 4 指的是 节点值为1
		for (int i = 0; i < m - 1; i++) pre = pre.next;
		// 用双指针,进行链表翻转
		ListNode node = null;
		ListNode cur = pre.next;
		for (int i = 0; i < n - m + 1; i++)
		{
			ListNode tmp = cur.next;
			cur.next = node;
			node = cur;
			cur = tmp;
		}
		// 将翻转部分 和 原链表拼接
		pre.next.next = cur;
		pre.next = node;
		return dummy.next;

	}
}
