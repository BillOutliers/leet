

/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

思路：
    不能忽略k大于链表长度的情况
	形成环，并对长度取余
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k){
	if(!head) return head;
    struct ListNode *tail=head;
	struct ListNode *newHead=head;
	int span=1;
	while(tail->next)
	{
		tail=tail->next;
		span++;
	}
	tail->next=head;//形成环
	if(k%=len)
	{
		k=len-k;
		while(k>0)
		{
			k--;
			tail=tail->next;
		}
	}
	newHead=tail->next;
	tail->next=NULL;
	return newHead;
	
}