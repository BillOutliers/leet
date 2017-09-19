/*
A linked list is given such that each node contains an additional random pointer which 
could point to any node in the list or null.

Return a deep copy of the list.
���ƴ������ָ�������
     �������ָ�뵼�²����ڸ����������ɵĹ�����һ���Ը��ƣ����ָ��Ĳ�ȷ������Ҫ
	 ����ڵ㸴�ƽ������ٸ������ָ�룻����ڵ�a�����ָ��ָ��d,��ô���µĸ���������a'(a'�ǽڵ�a
	 �ĸ���)�����ָ��ָ��d'(d'�ǽڵ�d�ĸ���)��
˼·��
    ����1����ԭ��������������һ��hash��hashmap<�ɵ�ַ���µ�ַ>,�ȸ�����������hash��
	    Ȼ������������ͬʱ�ƶ�������randomָ�룬 a'->random = hashmap[a->random](��ָ�뵥������)��
	����2����ÿ�����ƽڵ���뵽ԭ�ڵ�ĺ��棬��ÿ���ڵ�������һ������ĸ�����
	       a->a'->b->b'->c->c' ....    a,b,c,...��ԭ�ڵ�  a',b',c',...�Ǹ��ƽڵ�
		   ����randomָ�룺һ��ԭ�ڵ�a�ĸ���a'=a->next, a->random�ĸ��� a'->random=a->random->next,
		   ��ָ�뵥������
		   ��֣�ԭ�ڵ�����Ϊ�������½ڵ�����Ϊż������ż������Ϊһ���µ������ɡ�
		
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
		unordered_map<RandomListNode*,RandomListNode*> hash; //<ԭ�ڵ�ָ�룬���ƽڵ�ָ��>
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
		while(h)   //����randomָ��
		{
			hash[h]->random=hash[h->random];
			h=h->next;
		}
		return ph;
    }
};




