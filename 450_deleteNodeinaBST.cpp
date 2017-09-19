/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).

Example:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

    5
   / \
  2   6
   \   \
    4   7

BST删除节点：
先找的节点的位置del；
根据是否存在左右孩子做出不同的选择，如果不存在左海子，直接跳过del结点指向其右孩子并删除del即可，
如果不存在右孩子，直接跳过del结点指向其左孩子并删除del；
如果左右孩子都存在，使其右孩子左支路的末端指向del的左孩子或者使del的左孩子的右支路的末端指向del的
右孩子并删除del

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        TreeNode* del=root;
        if(root->val ==key){
        	if(!root->right){
        		root=root->left;
        	}
        	else if(!root->left){
        		root=root->right;
        	}
        	else{
        		TreeNode* node=root->right;       		
        		while(node->left){
        			node=node->left;
        		}
        		node->left=root->left;
        		root=root->right;        		
        	}
        	delete del;        	
        }
        else if(root->val > key){
        	root->left=deleteNode(root->left,key);
        }else
        	root->right=deleteNode(root->right,key);
        return root;
    }
};

