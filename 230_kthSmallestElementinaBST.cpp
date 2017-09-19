/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth 
smallest frequently? How would you optimize the kthSmallest routine?
BST的中序遍历为升序，找到第k个节点即可
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
    int kthSmallest(TreeNode* root, int k) {
        int cnt=k;
        int target;
        inorder(root,cnt,target);
        return target;

    }
    void inorder(TreeNode* root,int &k,int &target)
    {
    	if(!root)return;
    	
    	if(root->left)inorder(root->left,k);
    	k--;
    	if(k==0){
    		target=root->val;
    		return;
    	}
    	inorder(root->right,k);
    }
};

