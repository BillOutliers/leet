

/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, 
only nodes itself can be changed.

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 /*
 利用双指针来修改head指针的值
 */
struct ListNode* swapPairs(struct ListNode* head)
{
	struct ListNode *per,*re;
	struct ListNode** tmp=&head;
	while((per=*tmp) && (re=per->next))
	{
		per->next=re->next;
		re->next=per;
		*tmp=re;
		tmp=&(per->next);
	}
    return head;
}

/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes 
is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
思路：
-1 -> 1 -> 2 -> 3 -> 4 -> 5
 |    |    |    | 
pre  cur  nex  tmp

-1 -> 2 -> 1 -> 3 -> 4 -> 5
 |         |    |    | 
pre       cur  nex  tmp

-1 -> 3 -> 2 -> 1 -> 4 -> 5
 |              |    |    | 
pre            cur  nex  tmp
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
	if(head==NULL || k==1) return head;
	int num=1,i;
	struct ListNode** hp=&head;
	struct ListNode *cur=head,*re,*tmp;
	while(cur=cur->next)
		num++;	
	while(num>=k)
	{	
        cur=*hp;
		re=cur->next;
		for(i=0;i<k-1;i++)
		{
			// tmp=re->next;
			// cur->next=tmp;
			// re->next=*hp;
			// *hp=re;
			// re=tmp;
			//tmp=re->next;
			cur->next=re->next;
			re->next=*hp;
			*hp=re;
			re=cur->next;
		}
		hp=&(cur->next);
		num-=k;
	}
    return head;
}
















