/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode {
     int val;
     struct ListNode *next;
  };
 #define INT_MIN -2147483648
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode *head=(struct ListNode*)malloc(sizeof(struct ListNode));
	head->val=INT_MIN;
	head->next=NULL;
	struct ListNode* p=head;
	while(l1 && l2)
	{
		if(l1->val > l2->val)
		{
			p->next=l2;
			l2=l2->next;
		}else{
			p->next=l1;
			l1=l1->next;
		}
		p=p->next;
	}
	p->next = l1 ? l1 : l2;
	return head->next;
}
struct ListNode* mergeTwoLists2(struct ListNode* l1, struct ListNode* l2)
{
	if(l1==NULL) return l2;
	if(l2==NULL) return l1;
	if(l1->val > l2->val)
	{
		l2->next=mergeTwoLists2(l1,l2->next);
		return l2;
	}else
	{
		l1->next=mergeTwoLists2(l1->next,l2);
		return l1;
	}
}
/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
思路：每次对两个链表进行排序
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    int i=0;
	if(listsSize==0)
		return NULL;
	while(listsSize>1)
	{
		for(i=0;i<listsSize/2;i++)
			lists[i]=mergeTwoLists(lists[i],lists[listsSize-i-1]);
		listsSize=(listsSize+1)>>1;
	}
	return lists[0];
}











































