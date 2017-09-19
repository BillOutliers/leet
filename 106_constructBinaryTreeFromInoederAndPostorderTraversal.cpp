
/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty()||postorder.empty()) return NULL;
		unordered_map<int,int> mp;
		for(int i=0;i<inorder.size();i++)
			mp[inorder[i]]=i;
		return helper(postorder,0,postorder.size()-1,0,inorder.size()-1,mp);
    }
	TreeNode* helper(vector<int>&postorder,int start,int end,int is,int ie,unordered_map<int,int> &mp)
	{
		if(start>end || is>ie) return NULL;
		TreeNode* root=new TreeNode(postorder[end]);
		int index=mp[postorder[end]];
		root->left=helper(postorder,start,start+index-is-1,is,index-1,mp);
		root->right=helper(postorder,start+index-is,end-1,index+1,ie,mp);
		return root;
	}
};



