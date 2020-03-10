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
    
    int helper(TreeNode* root, int mx, int mn){
        if(root==NULL)return mx - mn;
        mx = max(root->val, mx);
        mn = min(root->val, mn);
        return max(helper(root->left,mx,mn), helper(root->right,mx,mn));
    }
    
    
    int maxAncestorDiff(TreeNode* root) {
        
        return helper(root, root->val, root->val);
    }
};
