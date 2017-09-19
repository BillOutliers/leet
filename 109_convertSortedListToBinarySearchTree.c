

/*
Given a singly linked list where elements are sorted in ascending order, 
convert it to a height balanced BST.

BST:Binary search tree 平衡二叉查找树
平衡二叉查找树定义为每个节点的两个子树高度差不超过1.
     若左子树不为空，则左子树上的所有节点的值均小于它的根节点的值
	 若右子树不为空，则右子树上的所有节点的值均大于它的根节点的值
	 左、右子树也分别为二叉排序树
二叉查找树是插入，排序，查找的平均时间复杂度都是O(Log(n))，最差情况是O(n),
二叉树的平衡因子是该结点的左子树的深度减去它的右子树的深度，平衡二叉树的BF因子绝对为1。	 

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
	while(fast!=tail && fast->next!=tail)//快慢指针寻找中间节点
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





















