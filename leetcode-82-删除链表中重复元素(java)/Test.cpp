﻿给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1 :
输入 : 1->2->3->3->4->4->5
输出 : 1->2->5

示例 2 :
输入 : 1->1->1->2->3
输出 : 2->3

//解题思路：
//迭代 快慢指针, 用快指针跳过那些有重复数组, 慢指针负责和快指针拼接!

class Solution {
	public ListNode deleteDuplicates(ListNode head) {
		if (head == null) return head;
		ListNode dummy = new ListNode(-1000);
		dummy.next = head;
		ListNode slow = dummy;
		ListNode fast = dummy.next;
		while (fast != null) {
			while (fast.next != null && fast.val == fast.next.val) fast = fast.next;
			if (slow.next == fast) slow = slow.next;
			else slow.next = fast.next;
			fast = fast.next;
		}
		return dummy.next;
	}
}
