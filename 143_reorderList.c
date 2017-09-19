
/*
Given a singly linked list L: L0?L1?…?Ln-1?Ln,
reorder it to: L0?Ln?L1?Ln-1?L2?Ln-2?…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}
思路：
    把链表从中间分成两个链表，后半部分链表反序，然后重组链表
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head){
    if(!head || !head->next) return ;
	struct ListNode *firstPart=head;
	struct ListNode *secondPart=head;
	struct ListNode *fast=head,*mid=head;
	while(fast->next && fast->next->next)//把链表分成两部分
		fast=fast->next->next,mid=mid->next;
	secondPart=mid->next;
	mid->next=NULL;
	reverseList(&secondPart);//把第二部分链表反序
	
	fast=head,mid=secondPart;
	struct ListNode *tmpf,*tmpm;
	while(mid)  //重新连接成一个链表
	{
		tmpf=fast->next;
		fast->next=mid;
		fast=tmpf;
		tmpm=mid->next;
		mid->next=tmpf;
		mid=tmpm;	
	}
	
}

void reverseList(struct ListNode** head)
{
	if(!(*head) || !(*head)->next)return ;
	struct ListNode **h=head;
	struct ListNode *cur=*h,*pre;
	pre=cur->next;
	while(pre)
	{
		cur->next=pre->next;
		pre->next=*h;
		*h=pre;
		pre=cur->next;
	}
}
