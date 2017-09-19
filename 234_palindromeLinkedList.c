/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
�ж�һ���������Ƿ�Ϊ���� 
˼·1��
     �������벿�ַ������У�Ȼ�������ͷ�����벿�ֿ�ʼλ�ñȽϼ��ɡ�
˼·2��
	���õݹ麯����ջ����ʽ���ݹ鵽��������һ���ڵ����һ���ڵ�Ƚϣ�Ȼ��
	���м�ڵ��ƶ���
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




