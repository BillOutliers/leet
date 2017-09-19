/*
Given a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
注意保存链表头
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head){
	if(!head || !head->next) return head;
    int val=head->val;
	struct ListNode *tmp=head->next;
	if(tmp->val != val)
	{
		head->next=deleteDuplicates(tmp);
		return head;
	}
	else
	{
		while(tmp && tmp->val==val) tmp=tmp->next;
		return deleteDuplicates(tmp);
	}
}
struct ListNode* deleteDuplicates(struct ListNode* head){
	if(!head || !head->next) return head;
    struct ListNode **h=&head;
	struct ListNode *fast=NULL;
	while(*h)
	{
		fast=*h;
		if(fast->next && (*h)->val == fast->next->val)
		{
			while(fast && (*h)->val == fast->val)
				fast=fast->next;
			*h=fast;
		}
		else
			h=&((*h)->next);
	}
	return head;
	
}