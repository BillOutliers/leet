

/*
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely 
filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
完全二叉树：除了最后一层，第i+1层都有2^i个节点，最后一层可能缺失从右边开始连续的
几个节点

等比数列求和公式：
Sn = a(1-q^n)/(1-q) 
2^0 + 2^1 + 2^2+ ...+2^(n-1)=2^n -1

寻找最后一层从右边数第一个不为空的节点，采用二分法查找，通过本节点的层数h(同过一直计算
左支点的个数)与右节点的层数h2比较来把树分成两个子树，如果h==h2-1则说明左子树为满二叉树，
则转向右子树计算......
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
    int countNodes(TreeNode* root) {//Time linit exceeded
        if(!root) return 0;
        return countNodes(root->left)+countNodes(root->right)+1;
    }
    int height(TreeNode* root){
    	int i=0;
    	while(root){
    		root=root->left;
    		i++;
    	}
    	return i;
    }
    int countNodes(TreeNode* root) {
        int h=height(root);
        return h==0 ? 0 : height(root->right)==h-1 ? (1<<h-1) + countNodes(root->right) : (1<<h-2) + countNodes(root->left);
    }
};

