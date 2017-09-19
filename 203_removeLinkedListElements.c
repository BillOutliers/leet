
/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if(!head) return head;
	struct ListNode **h=&head;
	while(*h)
	{
		if((*h)->val == val)
			while(*h && (*h)->val == val)
				*h=(*h)->next;
		else	
			h=&((*h)->next);
	}
	return head;
}