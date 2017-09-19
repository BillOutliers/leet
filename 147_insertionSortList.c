
/*
Sort a linked list using insertion sort.
ֱ�Ӳ������򣬴�������߿�ʼ����ÿ�����ƶ�һ�Σ�����С����������
���ұߵ��������������������ǰ�������Ѿ������򻯵ġ�
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    if(!head || !head->next) return head;
	struct ListNode *p=head,*findplace=NULL,*tmp=NULL;
	struct ListNode *fakeHead=(struct ListNode*)malloc(sizeof(struct ListNode));
	fakeHead->next=head;
	while(p->next)
	{
		if(p->next->val < p->val)
		{
			findplace=fakeHead;
			while(findplace->next->val < p->next->val)
				findplace=findplace->next;
			tmp=p->next;
			p->next=tmp->next;
			tmp->next=findplace->next;
			findplace->next=tmp;
		}
	    else
			p=p->next;
	}
	return fakeHead->next;
}
