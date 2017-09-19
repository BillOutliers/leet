/*
A linked list is given such that each node contains an additional random pointer which 
could point to any node in the list or null.

Return a deep copy of the list.
复制带有随机指针的链表；
     带有随机指针导致不能在复制链表生成的过程中一次性复制，随机指针的不确定性需要
	 链表节点复制结束后再复制随机指针；如果节点a的随机指针指向d,那么在新的复制链表中a'(a'是节点a
	 的副本)的随机指针指向d'(d'是节点d的副本)。
思路：
    方法1：对原链表与新链表做一个hash表，hashmap<旧地址，新地址>,先复制链表并生成hash表，
	    然后再两个链表同时移动来复制random指针， a'->random = hashmap[a->random](空指针单独处理)；
	方法2：把每个复制节点插入到原节点的后面，即每个节点后面插入一个自身的副本，
	       a->a'->b->b'->c->c' ....    a,b,c,...是原节点  a',b',c',...是复制节点
		   复制random指针：一个原节点a的副本a'=a->next, a->random的副本 a'->random=a->random->next,
		   空指针单独处理
		   拆分：原节点链表为奇数，新节点链表为偶数，把偶数连接为一个新的链表即可。
		
*/

//**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return head;
		RandomListNode *ph=new RandomListNode(head->label);
		RandomListNode *p=ph,*h=head;
		unordered_map<RandomListNode*,RandomListNode*> hash; //<原节点指针，复制节点指针>
		hash[head]=ph;
		while(h->next)
		{
			RandomListNode *node=new RandomListNode(h->next->label);
			hash[h->next]=node;
			p->next=node;
			p=p->next;
			h=h->next;
		}
		h=head;
		while(h)   //复制random指针
		{
			hash[h]->random=hash[h->random];
			h=h->next;
		}
		return ph;
    }
};




