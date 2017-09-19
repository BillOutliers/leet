/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
判断一个单链表是否为回文 
思路1：
     把链表后半部分反序排列，然后从链表头部与后半部分开始位置比较即可。
思路2：
	利用递归函数的栈处理方式，递归到链表的最后一个节点与第一个节点比较，然后
	向中间节点移动。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    if(!head || !head->next) return 1;
	struct ListNode *fast=head,*slow=head;
	while(fast->next && fast->next->next)
		fast=fast->next->next,slow=slow->next;
	struct ListNode *secondHead=slow->next;
	reverseList(&secondHead);
	while(secondHead)
	{
		if(head->val != secondHead->val)
			return 0;
		head=head->next;
		secondHead=secondHead->next;
	}
	return 1;
}
void reverseList(struct ListNode **head)
{
	if(!(*head) || !(*head)->next) return ;
	struct ListNode **h=head;
	struct ListNode *cur=*h,*pre=NULL;
	pre=cur->next;
	while(pre)
	{
		cur->next=pre->next;
		pre->next=*h;
		*h=pre;
		pre=cur->next;
	}
	
}




