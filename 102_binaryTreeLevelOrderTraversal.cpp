

/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
使用一个队列来实现层次遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
		if(!root) return res;
		queue<TreeNode*> q;
		q.push(root);
		while(!q.empty())
		{
			int len=q.size();
			vector<int> tmp;
			for(int i=0;i<len;i++)
			{
				TreeNode* node=q.front();
				tmp.push_back(node->val);
				q.pop();
				if(node->left) q.push(node->left);
				if(node->right) q.push(node->right);
			}
			res.push_back(tmp);
		}
		return res;
	}	
};



