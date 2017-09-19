
/*


Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
ͨ��������ǰ����������������ԭ��������
ǰ��������ȷ��ʸ��ڵ㣬Ȼ����ڵ㡢�ҽڵ�
����������ȷ�����ڵ㣬Ȼ����ڵ㡢�ҽڵ�
ͨ��ǰ������ҵ�ÿ�������ĸ��ڵ㣬ͨ����������ҵ�ÿ�����������Һ��ӷ�Χ

*/



// Definition for a binary tree node.
 
 
 #include <stdio.h>
 #include <iostream>
 #include <vector>
 #include <map>
 #include <hash_map>
 #include <unordered_map>
 using namespace std;
 //using namespace __gnu_cxx; 
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {// 12ms
		if(preorder.empty() || inorder.empty()) return NULL;
        map<int,int> inorder_map;
		for(int i=0;i<inorder.size();i++)//�����������ֵ��Ϊ����λ����Ϊֵ�洢��hash����
			inorder_map[inorder[i]]=i;
		return constructTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inorder_map);
    }
	TreeNode* constructTree(vector<int>& preorder,int pl,int pr,vector<int>& inorder,int inl,int inr,map<int,int>& inorder_map)
	{
		if(pl>pr || inl>inr)
			return NULL;
		TreeNode *tree=new TreeNode(preorder[pl]);
		int index=inorder_map[preorder[pl]];//���ڵ�����������е�λ��
		tree->left=constructTree(preorder,pl+1,index-inl+pl,inorder,inl,index-1,inorder_map);
		tree->right=constructTree(preorder,pl+index-inl+1,pr,inorder,index+1,inr,inorder_map);
		return tree;
	}
	TreeNode* buildTree2(vector<int>& preorder, vector<int>& inorder)//29ms 
	{
		if(preorder.empty() || inorder.empty()) return NULL;
		return constructTree2(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1); 
	}
	TreeNode* constructTree2(vector<int>& preorder,int pl,int pr,vector<int>& inorder,int inl,int inr)
	{
		if(pl>pr || inl>inr) return NULL;
		TreeNode* root=new TreeNode(preorder[pl]);
		int index=inl;
		for(;index<=inr;index++)//���ڵ�����������е�λ��
			if(preorder[pl]==inorder[index]) break;
		root->left=constructTree2(preorder,pl+1,index-inl+pl,inorder,inl,index-1);
		root->right=constructTree2(preorder,pl+index-inl+1,pr,inorder,index+1,inr);
		return root;
		
	}

};
void printtree(struct TreeNode* root)
{
	if(!root) return;
	cout<<root->val<<endl;
	printtree(root->left);
	
	printtree(root->right);
}
int main()
{
	Solution mys;
	vector<int> preorder={1,2,4,5,3,6,8,9};
	vector<int> inorder={4,2,5,1,6,8,3,9};
	struct TreeNode* root=mys.buildTree(preorder,inorder);
	printtree(root);
	return 0;
}





















