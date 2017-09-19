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
���������������������д������ң�ż���д�������֮���α�����
����жϺ�ʱʲôʱ��������ң�ʲôʱ�����������Ҫ����ļ�¼��
��Ϣ�����������б�����BFS�������ö���ʵ�֣�������ÿ�ζ���ȡ��ǰ��ʱ��
�洢��һ�У�ÿһ�п�ʼ��ȡʱ��ȡ�����ڶ��еĴ�С�������ж��ٸ��ڵ㣬
���ڵ��ȡ��洢��˳��Ϊindex = reverse ? n-i-1 : i��indexΪ�洢��λ�ã�
nΪ���еĴ�С,iΪ�ڶ����е�λ�ã�reverseΪ�Ƿ���

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



