/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.
思路：BST的中序遍历的升序列


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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
		vector<int> v;
		inorder(root,v);
		for(int i=0;i<v.size()-1;i++)
			if(v[i]>=v[i+1]) return false;
		return true;
    }
	void inorder(TreeNode*root,vector<int>& v)
	{
		if(!root) return;
		inorder(root->left,v);
		v.push_back(root->val);
		inorder(root->right,v);
	}
	
	bool isValidBST(TreeNode* root) {
		long preVal=LONG_MIN;
		return inorder_chech(root,preVal);
	}
	bool inorder_chech(TreeNode* root,long &preVal)
	{
		if(!root) return true;
		if(!inorder_chech(root->left,preVal)) return false;
		if(root->val <= preVal) return false;
		preVal=root->val;
		if(!inorder_chech(root->right,preVal)) return false;
		return true;
	}
};


