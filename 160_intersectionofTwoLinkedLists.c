/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
思路1：
    两个链表同时向前移动，如果遇到相同的节点则返回该节点；如果链表A走到最后，则该指针
	指向链表B的头结点，两个指针继续移动；如果链表B走到最后，则该指针
	指向链表A的头结点，两个指针继续移动；当两个指针都为NULL时，则两个链表没有交点。
	如果链表A的节点数为a,链表B的节点数为b，两个移动的指针都最多移动a+b个节点。
思路2：
    与思路1相似，都是利用两个链表的长度，先求出两个链表的长度差m，让节点多的链表先移动
	m个节点，然后两个链表同时移动；如果有相同的节点，则返回该节点，如果两个链表走到最后没有
	交点，则返回NULL。
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









