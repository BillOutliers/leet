/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input. 
The first node is considered odd, the second node even and so on ...
把奇数节点放在前面，偶数节点放在后面
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    if(!head || !head->next || !head->next->next) return head;
	struct ListNode *evenP=head->next,*insert_r=head,*oddP;
	while(evenP && evenP->next)
	{
		oddP=evenP->next;
		evenP=evenP->next->next;
		oddP->next=insert_r->next;
		insert_r->next=oddP;
		insert_r=insert_r->next;
	}
	return head;//超时  ？？？？？
}
struct ListNode* oddEvenList(struct ListNode* head) {
    if(!head) return head;
	struct ListNode *evenP=head->next,*evenhead=head->next,*oddP=head;
	while(evenP && evenP->next)
	{
		oddP->next=evenP->next;
		oddP=oddP->next;
		evenP->next=oddP->next;
		evenP=evenP->next;
	}
	oddP->next=evenhead;
	return head;
	
	return head;
}



