/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
判断链表中是否有环?如果有环找到环开始的节点
     1.使用快慢指针判断是否有环,快指针是慢指针的2倍
	 2.如果有环，寻找环开始节点
	     链表开始节点为A，环开始节点为B，快慢指针相遇在环中的节点为C，如果A到B的节点数为x,B到C的节点数为y,C到B的节点数
		 为z，则快慢指针相遇时，设快指针已经在环内循环n圈，则 2(x+y)=n(y+z)+z ==> x=(n-1)(y+z)+z，说明如果快慢指针相遇时，
		 在A点一个指针与C点的一个指针，两个指针的运动速度相同，则他们会在B点相遇，相遇处B点记为环的开始位置节点。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if(!head) return head;
	struct ListNode *fast=head,*slow=head,*begins=head;
	while(fast->next && fast->next->next)
	{
		fast=fast->next->next;
		slow=slow->next;
		if(fast==slow)//存在环
		{
			while(slow!=begins)//寻找环的开始节点
			{
				slow=slow->next;
				begins=begins->next;
			}
			return begins;
		}
	}
	return NULL;
}