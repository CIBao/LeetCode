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
    TreeNode* increasingBST(TreeNode* root) {
        return helper(root, NULL);
    }
    
    TreeNode* helper(TreeNode* node, TreeNode* pre){
        if(node == NULL) return pre;
        TreeNode* res = helper(node->left, node);
        node->left = NULL;
        node->right = helper(node->right, pre);
        return res;
    }
};
