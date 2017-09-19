
/*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

   
二叉查找树：
    左节点小于父节点，父节点小于右节点
	
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
    vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> res;
		if(n<=0) return res;
        return generate(1,n);
    }
	vector<TreeNode*> generate(int begin,int end)
	{
		vector<TreeNode*> res;
		if(begin>end)
		{
			res.push_back(NULL);
			return res;
		}
		for(int i=begin;i<=end;i++)
		{
			vector<TreeNode*> leftTree=generate(begin,i-1);
			vector<TreeNode*> rightTree=generate(i+1,end);
			for(int j=0;j<leftTree.size();j++)
				for(int k=0;k<rightTree.size();k++)
				{
					TreeNode* father=new TreeNode(i);
					res.push_back(father);
					father->left=leftTree[j];
					father->right=rightTree[k];
				}
		}
		return res;
	}
};







