

/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return NULL;
		return helper(nums,0,nums.size()-1);
    }
	TreeNode* helper(vector<int>& nums,int left,int right)
	{
		if(left>right) return NULL;
		int mid=(left+right)>>1;
		TreeNode* root=new TreeNode(nums[mid]);
		root->left=helper(nums,left,mid-1);
		root->right=helper(nums,mid+1,right);
		return root;
	}
};




