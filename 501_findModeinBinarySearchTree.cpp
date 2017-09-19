
/*
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
For example:
Given BST [1,null,2,2],
   1
    \
     2
    /
   2
return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).

第一遍中序遍历找出出现最多的值的次数
第二遍把出现最多次的值保存起来
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
    vector<int> findMode(TreeNode* root) {
        std::vector<int> modes;
        if(!root) return modes;
        int maxCnt=0,flag=0,cnt=0,preVal;
        inorder(root,maxCnt,flag,cnt,preVal,modes);
        flag=1;
        cnt=0;
        inorder(root,maxCnt,flag,cnt,preVal,modes);
        return modes;

    }
    void inorder(TreeNode* root,int &maxCnt,int flag,int &cnt,int &preVal,std::vector<int> &modes){
    	if(!root) return;
    	inorder(root->left,maxCnt,flag,cnt,preVal,modes);
    	handleVal(root->val,maxCnt,flag,cnt,preVal,modes);
    	inorder(root->right,maxCnt,flag,cnt,preVal,modes);
    }
    void handleVal(int val,int &maxCnt,int flag,int &cnt,int &preVal,std::vector<int> &modes){
    	if(preVal != val){
    		preVal=val;
    		cnt=0;
    	}
    	cnt++;
    	if(cnt > maxCnt){
    		maxCnt=cnt;    		
    	}else if(cnt==maxCnt){
    		if(flag==1){
    			modes.push_back(val);
    		}
    	}
    }
};
