
/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes 
v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, 
since a node can be a descendant of itself according to the LCA definition.
寻找给定两个节点最近的共同父节点。
利用二叉查找树的性质，从根节点开始二分查找：
如果两个节点其中有一个节点与根节点相等，则根节点即为最低父节点；
如果两个节点都大于根节点，则两个节点肯定在根节点的右边，选择右半部分子树重复过程；
如果两个节点都小于根节点，则两个节点肯定在根节点的左半部分，选择左子树进行重复过程即可；
如果两个节点一个大于根节点一个小于根节点，则根节点即使最低父节点。
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	if(q->val > p->val) return lowestCommonAncestor(root,q,p); 
    	if(root->val == p->val || root->val==q->val) return root;
       	if(root->val >p->val)
       		return lowestCommonAncestor(root->left,p,q);
        else if(root->val < q->val)
        	return lowestCommonAncestor(root->right,p,q);
        else
        	return root;
    }
};


