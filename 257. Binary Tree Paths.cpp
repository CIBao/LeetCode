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
    void helper(vector<string>& res,TreeNode* root, string s){
        if(!root->left && !root->right){
            s += to_string(root->val);
            res.push_back(s);
        }
        
        if(root->left) helper(res, root->left, s+to_string(root->val) + "->");
        if(root->right) helper(res, root->right, s+to_string(root->val) + "->");
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root==NULL)return res;
        
        helper(res, root, "");
        
        return res;
    }
};
