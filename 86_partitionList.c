

/*
Given a linked list and a value x, partition it such that all nodes less than x come 
before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
ע�⣺
    ���ڵ�һ���ڵ���Ҫ����ʱ��head->val >=valʱ����Ҫ��head֮ǰ����ڵ�
	��Ҫһ��head_r
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x){
	if(!head) return head;
    struct ListNode *head_r=(struct ListNode*)malloc(sizeof(struct ListNode));
	head_r->next=head;
	struct ListNode *insert_r=head_r;
	struct ListNode *fast=head;
	while(insert_r->next && insert_r->next->val < x)//Ѱ�ҵ�һ����С��x��ǰһ���ڵ�
	{
		insert_r=insert_r->next;
	}
	struct ListNode *fast_r=insert_r;
	fast=insert_r->next;//��һ����С��x�Ľڵ�
	while(fast)
	{
		if(fast->val >= x)
		{
			fast_r=fast;
			fast=fast->next;			
		}
		else
		{
			fast_r->next=fast->next;
			fast->next=insert_r->next;
			insert_r->next=fast;
			insert_r=fast;
			fast=fast_r->next;
		}			
	}
	return head_r->next;
	
}

struct ListNode* partition(struct ListNode* head, int x){
	if(!head) return head;
    struct ListNode *head_r=(struct ListNode*)malloc(sizeof(struct ListNode));
	head_r->next=NULL;
	struct ListNode *h_r=head_r;
    struct ListNode *head_b=(struct ListNode*)malloc(sizeof(struct ListNode));
	head_b->next=NULL;
	struct ListNode *h_b=head_b;
	struct ListNode *tmp=head;
	while(tmp)
	{
		if(tmp->val < x)
		{
			h_r->next=tmp;
			h_r=h_r->next;
		}
		else
		{
			h_b->next=tmp;
			h_b=h_b->next;
		}
		tmp=tmp->next;
	}
	h_b->next=NULL;
	h_r->next=head_b->next;
	return head_r->next;
}



















