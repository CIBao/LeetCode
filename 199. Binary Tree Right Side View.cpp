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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)return {};
        vector<int> res;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()){
            int m = Q.size();
            int tmp;
            for(int i = 0; i < m; i++){
                auto x = Q.front(); Q.pop();
                tmp = x->val;
                if(x->left)Q.push(x->left);
                if(x->right)Q.push(x->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
