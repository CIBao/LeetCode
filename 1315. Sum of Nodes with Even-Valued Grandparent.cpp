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
    
    
    int sumEvenGrandparent(TreeNode* root,int p = 1, int gp = 1) {
        return root? sumEvenGrandparent(root->left, root->val, p)+
            sumEvenGrandparent(root->right, root->val, p)+(gp%2==0?root->val:0):0;
    }
};
