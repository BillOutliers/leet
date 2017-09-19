
/*
Sort a linked list in O(n log n) time using constant space complexity.

由于要求时间复杂度为O(nlogn)，一般为快速排序，归并排序、堆排序，在链表中
快速排序实现难于归并排序，考虑到常态空间，在归并排序中充分利用头指针即可解决空间
的问题。
归并排序的基本思想是：找到链表的中间节点，然后递归对前半部分和后半部分分别进行归并排序，
最后对两个排好序的链表进行Merge 
两个升序子链合并为一个，只需要找到合并后的链表头部，然后把两个子链表按照大小顺序依次把节点
加入到链表头部后面即可。
jhj
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* sortList(struct ListNode* head) {
    if(!head || !head->next) return head;
	struct ListNode *fast=head,*slow=head;
	while(fast->next && fast->next->next)//寻找中间节点
		fast=fast->next->next,slow=slow->next;
	fast=slow;
	slow=slow->next;
	fast->next=NULL;
	fast=sortList(head);//前半部分的链表长度大于或等于后半部分的链表长度
	slow=sortList(slow);
	return mergeSort(fast,slow);
}
struct ListNode* mergeSort(struct ListNode *f,struct ListNode *s)
{
	struct ListNode *head=NULL;
	if(f && s)//寻找归并后的指针头，不需要制造一个假头部来浪费空间
	{
		 if(f->val >= s->val)
		 {
			 head=s;
			 s=s->next;
		 }else
		 {
			 head=f;
			 f=f->next;
		 }
	}else if(f)
		return f;
	else
		return s;
	struct ListNode *tmp=head;
	while(f && s)
	{
		if(f->val <= s->val)
		{
			tmp->next=f;
			f=f->next;
		}else
		{
			tmp->next=s;
			s=s->next;
		}
		tmp=tmp->next;
	}
	tmp->next = f ? f : s;
	return head;
}



