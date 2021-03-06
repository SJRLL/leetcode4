﻿给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1 :
输入 : 1->1->2
输出 : 1->2

示例 2 :
输入 : 1->1->2->3->3
输出 : 1->2->3

//解题思路：
//指定 cur 指针指向头部 head
//当 cur 和 cur.next 的存在为循环结束条件，当二者有一个不存在时说明链表没有去重复的必要了
//当 cur.val 和 cur.next.val 相等时说明需要去重，则将 cur 的下一个指针指向下一个的下一个，这样就能达到去重复的效果
//如果不相等则 cur 移动到下一个位置继续循环

/**
* Definition for singly-linked list.
* public class ListNode {
*     int val;
*     ListNode next;
*     ListNode(int x) { val = x; }
* }
*/
class Solution {
	public ListNode deleteDuplicates(ListNode head) 
	{
		ListNode cur = head;
		while (cur != null && cur.next != null) 
		{
			if (cur.val == cur.next.val) 
			{
				cur.next = cur.next.next;
			}
			else 
			{
				cur = cur.next;
			}
		}
		return head;
	}
}
