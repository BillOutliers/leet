
/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
		if(!root) return res;
		vector<int> tmp;
		dfs(root,sum,res,tmp);
		return res;
    }
	void dfs(TreeNode* root,int sum,vector<vector<int>> &res,vector<int> &tmp){
		if(!root) return ;
		sum -=root->val;
		tmp.push_back(root->val);
		if(!root->left && !root->right && sum==0) res.push_back(tmp);
		dfs(root->left,sum,res,tmp);
		if(root->left) tmp.pop_back();
		dfs(root->right,sum,res,tmp);
		if(root->right) tmp.pop_back();
	}
};

