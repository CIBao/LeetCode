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
    int maxDepth(TreeNode* root, int d = 0) {
        if(root==NULL){
            return d;
        }
        int m1 = maxDepth(root->left, d+1);
        int m2 = maxDepth(root->right, d+1);
        return max(m1, m2);
    }
};
