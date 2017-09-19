
/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the 
height of the tree.
ÿ�ε���next()����ʣ�����Сֵ
�ڶ���������У���������Ĵ�����Ǹ����ڵ�ֵ�İ���������
O(h)��memory��ֻ�ܱ������߶ȸ�Ԫ��
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode *root) {
        pushHeight(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }

    /** @return the next smallest number */
    int next() {
       TreeNode* topNode=st.top();
	   st.pop();
	   pushHeight(topNode->right);
	   return topNode->val;
    }
	void pushHeight(TreeNode* root)
	{
		while(root)
		{
			st.push(root);
			root=root->left;
		}
	}
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */