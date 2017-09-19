




/*



You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/











/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode header;
	struct ListNode *p=&header;
	int add_up=0;
	int sum=0;
	p->next = NULL;
	while(l1!=NULL || l2!=NULL || add_up)
	{
		sum=(l1!=NULL ? l1->val : 0) + (l2!=NULL ? l2->val : 0) +add_up;
		add_up=sum/10;
		if((p->next=(struct ListNode*)malloc(sizeof(struct ListNode)))==NULL)
			return NULL;
		p=p->next;
		p->next=NULL;
		p->val=sum%10;
		l1 = l1!=NULL ? l1->next : l1;
		l2 = l2!=NULL ? l2->next : l2;
	}
	return header.next;
}
