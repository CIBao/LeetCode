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
    set<int> s;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        for(auto n: to_delete){
            s.insert(n);
        }
        helper(res, root, true);
        return res;
    }
    
     TreeNode* helper(vector<TreeNode*>& res, TreeNode* root, bool isroot){
        if(root==NULL)return NULL;
        bool isdelete = s.find(root->val) != s.end();
        if(isroot && !isdelete) res.push_back(root);
        root->left = helper(res, root->left, isdelete);
        root->right = helper(res, root->right, isdelete);
        return isdelete?NULL:root;
    }
    
};
