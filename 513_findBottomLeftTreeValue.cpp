/*
Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1
Example 2: 
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
Note: You may assume the tree (i.e., the given root node) is not NULL.
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *l=root;
        while(!q.empty()){
        	int len=q.size();
        	 l= q.front();
        	for(int i=0;i<len;i++){
        		TreeNode* node=q.front();
        		q.pop();
        		if(node->left) q.push(node->left);
        		if(node->right) q.push(node->right);
        	}
        }
        return l->val;
    }
};
