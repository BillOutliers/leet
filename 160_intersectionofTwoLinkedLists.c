/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 �� a2
                   �K
                     c1 �� c2 �� c3
                   �J            
B:     b1 �� b2 �� b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
˼·1��
    ��������ͬʱ��ǰ�ƶ������������ͬ�Ľڵ��򷵻ظýڵ㣻�������A�ߵ�������ָ��
	ָ������B��ͷ��㣬����ָ������ƶ����������B�ߵ�������ָ��
	ָ������A��ͷ��㣬����ָ������ƶ���������ָ�붼ΪNULLʱ������������û�н��㡣
	�������A�Ľڵ���Ϊa,����B�Ľڵ���Ϊb�������ƶ���ָ�붼����ƶ�a+b���ڵ㡣
˼·2��
    ��˼·1���ƣ�����������������ĳ��ȣ��������������ĳ��Ȳ�m���ýڵ����������ƶ�
	m���ڵ㣬Ȼ����������ͬʱ�ƶ����������ͬ�Ľڵ㣬�򷵻ظýڵ㣬������������ߵ����û��
	���㣬�򷵻�NULL��
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(!headA || !headB) return NULL;
	struct ListNode *a=headA,*b=headB;
	while(a && b && a!=b)
	{
		a=a->next;
		b=b->next;
		if(a==b)
			return a;
		if(!a)
			a=headB;
		if(!b)
			b=headA;
	}
	return a;
}

	while(a || b)
	{
		if(!a)
			a=headB;
		if(!b)
			b=headA;
		if(a==b)
			return a;
		a=a->next;
		b=b->next;
	}
	return NULL;









