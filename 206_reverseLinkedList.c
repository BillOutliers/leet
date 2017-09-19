/*
Reverse a singly linked list.
Á´±í·´Ğò

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(!head || !head->next) return head;
	struct ListNode **h=&head;
	struct ListNode *cur=head,*pre=head->next;
	while(pre)
	{
		cur->next=pre->next;
		pre->next=(*h);
		*h=pre;
		pre=cur->next;
	}
	return head;
}


