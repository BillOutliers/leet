

/*

Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?

用迭代实现二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
		stack<TreeNode*> st;
		if(root) st.push(root);
		while(!st.empty())
		{
			TreeNode* ptr=st.top();
			res.push_back(ptr->val);
			st.pop();
			if(ptr->right) st.push(ptr->right);
			if(ptr->left) st.push(ptr->left);
		}
		return res;
    }
	vector<int> preorderTraversal2(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> st;
		if(root) st.push(root);
		while(!st.empty())
		{
			TreeNode* ptr=st.top();
			while(ptr->left)
			{
				res.push_back(ptr->val);
				ptr=ptr->left;
				st.push(ptr);
			}
			res.push_back(ptr->val);
			do{
				ptr=st.top();
				st.pop();
			}while(ptr->right==NULL && !st.empty());
			if(ptr->right)
				st.push(ptr->right);
		}
		return res;
	}
};










