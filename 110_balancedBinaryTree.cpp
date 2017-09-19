/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree 
in which the depth of the two subtrees of every node never differ by more than 1.

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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
		return depth(root)!=-1;
    }
	int depth(TreeNode* root)
	{
		if(!root) return 0;
		int leftdepth=depth(root->left);
		if(leftdepth==-1) return -1;
		int rightdepth=depth(root->right);
		if(rightdepth==-1) return -1;
		if(abs(leftdepth-rightdepth)>1) return -1;
		return max(leftdepth,rightdepth)+1;
	}
};



