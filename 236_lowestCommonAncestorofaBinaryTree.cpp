/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between 
two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a 
node to be a descendant of itself).”

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of 
nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
思路1：
1:利用二个栈来存储两个节点的路径
2：使路径长的节点，从栈顶pop节点，直到两个栈的长度相同
3：开始从栈顶比较，如果相等，即为最低的父节点

思路2：
    两个节点在同一个子树或不同子树，在同一个子树直接返回遇到的第一个节点即可；
    在不同的子树，当两个节点都遇到后，下一个父节点即是所求
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        stack<TreeNode*> sp,sq;
        findNodePath(root,q,sq);
        findNodePath(root,p,sp);
        while(!sq.empty() && !sp.empty()){
        	if(sq.size()>sp.size())
        		sq.pop();
        	else if(sq.size()<sp.size())
        		sp.pop();
        	else
        		break;
        }
         while(!sq.empty() && !sp.empty()){
         	if(sq.top()==sp.top())
         		return sq.top();
         	sq.pop();
         	sp.pop();
         }
         return NULL;
    }
    void findNodePath(TreeNode* root,TreeNode* target,stack<TreeNode*> &st){
    	if(!root) return;
    	st.push(root);
    	if(st.top()==target) return;
 		if(root->left) findNodePath(root->left,target,st);	
 		if(st.top()!=target && root->right) findNodePath(root->right,target,st);
 		if(st.top()!=target) st.pop();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	if(!root || root==p || root==q) return root;
    	TreeNode* left=lowestCommonAncestor(root->left,p,q);
    	TreeNode* right=lowestCommonAncestor(root->right,p,q);
    	return !left ? right : !right ? left : root;
    }
};


