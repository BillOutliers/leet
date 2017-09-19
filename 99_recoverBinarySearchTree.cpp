
/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
修改后两个元素：第一个元素总是大于下一个元素，而第二个元素总是小于其前一个元素。
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
    void recoverTree(TreeNode* root) {
        if(!root) return;
		TreeNode* pre,*first,*second;
		pre=first=second=NULL;
		inorder(root,&pre,&first,&second);
		if(first)
		{
			int tmp=first->val;
			first->val=second->val;
			second->val=tmp;
		}
    }
	void inorder(TreeNode* root,TreeNode** pre,TreeNode** first,TreeNode** second){
		if(!root) return;
		inorder(root->left,pre,first,second);
		if(*pre && (*pre)->val > root->val){
			if(!*first){
				*first=*pre;
				*second=root;
			}
			else
				*second=root;
		}
		*pre=root;
		inorder(root->right,pre,first,second);
	}
};




