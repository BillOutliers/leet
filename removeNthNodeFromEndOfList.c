

/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

删除链表从后面数第n个节点e，需要知道链表从后面数第n+1个节点e_r的指针
若链表总结点数为sum,则e_r的在链表中的位置sum-n (从链表头开始数)
采用前后指针法来找到e_r的位置，只需遍历一遍链表,前后指针相差的值就是n,
当前指针从链表头遍历到尾部时，后指针正好遍历到e_r的位置。
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


