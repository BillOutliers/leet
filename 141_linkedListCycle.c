/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
�ж��������Ƿ��л�
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head){
    if(!head) return 0;
	struct ListNode *fast=head,*slow=head;
	while(fast->next && fast->next->next)
	{
		fast=fast->next->next;
		slow=slow->next;
		if(fast==slow) //����л�����ָ���ܹ�׷����ָ��
			return 1;
	}
	return 0;	
}