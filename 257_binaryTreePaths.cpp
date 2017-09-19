/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
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
    vector<string> binaryTreePaths(TreeNode* root) {
        std::vector<string> v;
        if(!root) return v;
        string tmp=to_string(root->val);
        dfs(root,v,tmp);
        return v;
    }
    void dfs(TreeNode* root,std::vector<string> &v,string tmp){
    	if(!root) return;
    	if(!root->left && !root->right){
    		v.push_back(tmp);
    		return;
    	}
    	if(root->left) dfs(root->left,v,tmp+"->"+to_string(root->left->val));
    	if(root->right) dfs(root->right,v,tmp+"->"+to_string(root->right->val));
    }
};

