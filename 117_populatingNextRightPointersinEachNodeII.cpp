
/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

*/


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
		TreeLinkNode *pre=NULL;//下一行中当前节点的前一个节点
		TreeLinkNode *headL=NULL;//下一行的从左边第一个非空节点
		TreeLinkNode *cur=root;
		while(cur)
		{
			while(cur)
			{
				if(cur->left){
					if(pre==NULL){
						headL=cur->left;
					}else{
						pre->next=cur->left;
					}
					pre=cur->left;
				}
				if(cur->right){
					if(pre==NULL){
						headL=cur->right;
					}else{
						pre->next=cur->right;
					}
					pre=cur->right;
				}
				cur=cur->next;
			}
			cur=headL;
			headL=NULL;
			pre=NULL;
		}
    }
};



