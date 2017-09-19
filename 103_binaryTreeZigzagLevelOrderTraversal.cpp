/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
遍历二叉树，按照奇数行从左向右，偶数行从右向左，之字形遍历。
如何判断何时什么时候从左向右，什么时候从右向左，需要额外的记录该
信息；二叉树按行遍历，BFS，可以用队列实现，队列中每次都读取当前行时，
存储下一行，每一行开始读取时，取出现在队列的大小即该行有多少个节点，
而节点读取后存储的顺序为index = reverse ? n-i-1 : i，index为存储的位置，
n为该行的大小,i为在队列中的位置，reverse为是否反序。

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
		queue<TreeNode*> q;
		bool reverse = false;
		if(root) q.push(root);
		while(!q.empty())
		{
			int n = q.size();
			vector<int> tmp(n);
			for(int i=0;i<n;i++)
			{
				int index = reverse ? n-i-1 : i;
				tmp[index]=q.front()->val;
				if(q.front()->left) q.push(q.front()->left);
				if(q.front()->right) q.push(q.front()->right);
				q.pop();
			}
			res.push_back(tmp);
			reverse=!reverse;
		}
		return res;
    }
};



