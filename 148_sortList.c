
/*
Sort a linked list in O(n log n) time using constant space complexity.

����Ҫ��ʱ�临�Ӷ�ΪO(nlogn)��һ��Ϊ�������򣬹鲢���򡢶�������������
��������ʵ�����ڹ鲢���򣬿��ǵ���̬�ռ䣬�ڹ鲢�����г������ͷָ�뼴�ɽ���ռ�
�����⡣
�鲢����Ļ���˼���ǣ��ҵ�������м�ڵ㣬Ȼ��ݹ��ǰ�벿�ֺͺ�벿�ֱַ���й鲢����
���������ź�����������Merge 
�������������ϲ�Ϊһ����ֻ��Ҫ�ҵ��ϲ��������ͷ����Ȼ��������������մ�С˳�����ΰѽڵ�
���뵽����ͷ�����漴�ɡ�
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
	while(fast->next && fast->next->next)//Ѱ���м�ڵ�
		fast=fast->next->next,slow=slow->next;
	fast=slow;
	slow=slow->next;
	fast->next=NULL;
	fast=sortList(head);//ǰ�벿�ֵ������ȴ��ڻ���ں�벿�ֵ�������
	slow=sortList(slow);
	return mergeSort(fast,slow);
}
struct ListNode* mergeSort(struct ListNode *f,struct ListNode *s)
{
	struct ListNode *head=NULL;
	if(f && s)//Ѱ�ҹ鲢���ָ��ͷ������Ҫ����һ����ͷ�����˷ѿռ�
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



