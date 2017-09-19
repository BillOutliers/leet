/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
�ж��������Ƿ��л�?����л��ҵ�����ʼ�Ľڵ�
     1.ʹ�ÿ���ָ���ж��Ƿ��л�,��ָ������ָ���2��
	 2.����л���Ѱ�һ���ʼ�ڵ�
	     ����ʼ�ڵ�ΪA������ʼ�ڵ�ΪB������ָ�������ڻ��еĽڵ�ΪC�����A��B�Ľڵ���Ϊx,B��C�Ľڵ���Ϊy,C��B�Ľڵ���
		 Ϊz�������ָ������ʱ�����ָ���Ѿ��ڻ���ѭ��nȦ���� 2(x+y)=n(y+z)+z ==> x=(n-1)(y+z)+z��˵���������ָ������ʱ��
		 ��A��һ��ָ����C���һ��ָ�룬����ָ����˶��ٶ���ͬ�������ǻ���B��������������B���Ϊ���Ŀ�ʼλ�ýڵ㡣
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if(!head) return head;
	struct ListNode *fast=head,*slow=head,*begins=head;
	while(fast->next && fast->next->next)
	{
		fast=fast->next->next;
		slow=slow->next;
		if(fast==slow)//���ڻ�
		{
			while(slow!=begins)//Ѱ�һ��Ŀ�ʼ�ڵ�
			{
				slow=slow->next;
				begins=begins->next;
			}
			return begins;
		}
	}
	return NULL;
}