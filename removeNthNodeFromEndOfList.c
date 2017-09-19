

/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

ɾ������Ӻ�������n���ڵ�e����Ҫ֪������Ӻ�������n+1���ڵ�e_r��ָ��
�������ܽ����Ϊsum,��e_r���������е�λ��sum-n (������ͷ��ʼ��)
����ǰ��ָ�뷨���ҵ�e_r��λ�ã�ֻ�����һ������,ǰ��ָ������ֵ����n,
��ǰָ�������ͷ������β��ʱ����ָ�����ñ�����e_r��λ�á�
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode* front=head;
    struct ListNode* back=head;
	struct ListNode* temp=NULL;
	while(front!=NULL)
	{
		front=front->next;
		if(n-- < 0 ) back=back->next;
	}
	if(n==0) 
	{
		temp=head;
		head=head->next;
	}
	else
	{
		temp=back->next;
		back->next=temp->next;
	}
	free(temp);
	return head;     
}


