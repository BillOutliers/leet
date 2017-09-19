

/*
Given a singly linked list where elements are sorted in ascending order, 
convert it to a height balanced BST.

BST:Binary search tree ƽ����������
ƽ��������������Ϊÿ���ڵ�����������߶Ȳ����1.
     ����������Ϊ�գ����������ϵ����нڵ��ֵ��С�����ĸ��ڵ��ֵ
	 ����������Ϊ�գ����������ϵ����нڵ��ֵ���������ĸ��ڵ��ֵ
	 ��������Ҳ�ֱ�Ϊ����������
����������ǲ��룬���򣬲��ҵ�ƽ��ʱ�临�Ӷȶ���O(Log(n))����������O(n),
��������ƽ�������Ǹý�������������ȼ�ȥ��������������ȣ�ƽ���������BF���Ӿ���Ϊ1��	 

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedListToBSTr(struct ListNode *head,struct ListNode *tail)
{
	if(head==tail)
		return NULL;
	if(head->next == tail)
	{
		struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		root->val=head->val;
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	struct ListNode *fast=head,*mid=head;
	while(fast!=tail && fast->next!=tail)//����ָ��Ѱ���м�ڵ�
	{
		mid=mid->next;
		fast=fast->next->next;
	}
	struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val=mid->val;
	root->left=sortedListToBSTr(head,mid);
	root->right=sortedListToBSTr(mid->next,tail);
	return root;
}
struct TreeNode* sortedListToBST(struct ListNode* head) {
    return sortedListToBSTr(head,NULL);
}





















