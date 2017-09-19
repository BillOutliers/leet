
/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

借助栈进行迭代来模拟函数栈

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
		if(!root) return res;
		stack<TreeNode*> s;
		TreeNode* p=root;
		while(!s.empty() || p)
		{
			if(p)
			{
				s.push(p);
				p=p->left;
			}
			else
			{
				TreeNode* pNode=s.top();
				res.push_back(pNode->val);
				s.pop();
				p=pNode->right;
			}
		}
		return res;
    }
};



