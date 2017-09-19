

/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
思路：
    当一个值重复出现时，只保留第一次出现的。
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
	struct ListNode *fast=head;
	while(fast)
	{
		if(fast->next && fast->val==fast->next->val)
		{
			fast->next=fast->next->next;
		}
		else
			fast=fast->next;
			
	}
	return head;
}