����һ�������һ���ض�ֵ x����������зָ���ʹ������С�� x �Ľڵ㶼�ڴ��ڻ���� x �Ľڵ�֮ǰ��

��Ӧ����������������ÿ���ڵ�ĳ�ʼ���λ�á�

ʾ�� :

���� : head = 1->4->3->2->5->2, x = 3
��� : 1->2->2->4->3->5
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		//����������㣬���ڱ���<x��ֵ��>=x��ֵ
		ListNode *before = new ListNode(0);
		ListNode *after = new ListNode(0);
		//��������ָ��ָ�������½����
		ListNode *p1 = before, *p2 = after;
		if (!head)
			return head;
		//��������<x��ֵ����before���棬>=x��ֵ����after����
		while (head)
		{
			if (head->val<x)
			{
				p1->next = head;
				p1 = p1->next;
				head = head->next;
			}
			else
			{
				p2->next = head;
				p2 = p2->next;
				head = head->next;
			}
		}
		//��before��after������
		p2->next = NULL;
		p1->next = after->next;
		return before->next;
	}
};
