/*

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
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
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> v;
        if(!root) return v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
        	int size_q=q.size();
        	TreeNode* tmp;
        	for(int i=0;i<size_q;i++){
                tmp=q.top();
                q.pop();
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
        	}
        	v.push_back(tmp->val);
        }
        return v;
    }
};