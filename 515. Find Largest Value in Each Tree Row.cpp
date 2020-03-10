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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(root==NULL)return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int m = q.size();
            int mx = INT_MIN;
            for(int i = 0; i < m; i++){
                auto x = q.front(); q.pop();
                mx = max(mx, x->val);
                if(x->left)q.push(x->left);
                if(x->right)q.push(x->right);
            }
            res.push_back(mx);
        }
        return res;
    }
};
