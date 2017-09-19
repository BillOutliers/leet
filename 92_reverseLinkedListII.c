

/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 <= m ?<=n <= length of list.

思路：
第一种： 链表头部的前一指针来保存链表头部
第二种： 使用双指针存储开始逆转的前一个的next指针地址
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    if(m==n) return head;//n>=m 
	struct ListNode *h=(struct ListNode*)malloc(sizeof(struct ListNode));
	h->next=head;
	struct ListNode *cur=head,*insert_r=h,*pre=NULL;
	n-=m;
	while(--m)
	{
		insert_r=insert_r->next;//寻找m的前一个节点
	}
	cur=insert_r->next;
	while(n--)
	{
		pre=cur->next;
		cur->next=pre->next;
		pre->next=insert_r->next;
		insert_r->next=pre;
	}
	return h->next;
}
struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    if(m==n) return head;//n>=m 
	struct ListNode **h=&head;
	struct ListNode *cur=head,*pre=NULL;
	n-=m;
	while(m>2)
	{
		cur=cur->next;
		m--;
	}
	h= m>1 ? &(cur->next) : &head;
	cur=*h;
	
	while(n--)
	{
		pre=cur->next;
		cur->next=pre->next;
		pre->next=*h;
		*h=pre;
	}
	
	return head;
}
















