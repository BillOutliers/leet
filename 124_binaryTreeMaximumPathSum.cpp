
/*
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
自下而上，计算每个节点的左支路值与右支路值和本节点值，比较最大值并更新加上该节点的支路
最大值(并与0比较，取大的)
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
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
		int tmp=findMax(root,sum);
		sum=max(tmp,sum);
		return sum;
    }
	int findMax(TreeNode* root,int &sum){
		if(!root) return 0;
		int leftSum=max(0,findMax(root->left,sum));
		int rightSum=max(0,findMax(root->right,sum));
		sum = (leftSum+rightSum+root->val) > sum ? leftSum+rightSum+root->val : sum;
		return leftSum > rightSum ? leftSum+root->val : rightSum+root->val;
	}
};


