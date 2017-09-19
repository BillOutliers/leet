
/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?

使用迭代实现二叉树的后序遍历

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
		stack<TreeNode*> st;
		TreeNode* lastVisit=NULL;
		TreeNode* ptr=root;
		while(ptr || !st.empty())
		{
			if(ptr)
			{
				st.push(ptr);
				ptr=ptr->left;
			}
			else
			{
				TreeNode* topNode=st.top();
				if(topNode->right && topNode->right!=lastVisit)
					ptr=topNode->right;
				else
				{
					res.push_back(topNode->val);
					lastVisit=topNode;
					st.pop();
				}
			}
		}
		return res;
    }
	vector<int> postorderTraversal2(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> st;
		if(root) st.push(root);
		while(!st.empty())
		{
			TreeNode* topNode=st.top();
			st.pop();
			res.push_back(topNode->val);
			if(topNode->left) st.push(topNode->left);
			if(topNode->right) st.push(topNode->right);
		}
		reverse(res.begin(),res.end());
		return res;
	}
};


















