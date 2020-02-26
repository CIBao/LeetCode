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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr)return res;
        queue<TreeNode*> q;
        vector<int> v;
        q.push(root);
        int flag = 0;
        //int level = 0;
        while(!q.empty()){
            int len = q.size();
            for(int i = 0; i < len; i++){
                TreeNode* nd = q.front();
                q.pop();
                v.push_back(nd->val);
                
                if(nd->left!=nullptr)q.push(nd->left);
                if(nd->right!=nullptr)q.push(nd->right);
                
                
            }
            if(flag)reverse(v.begin(), v.end());
            res.push_back(v);
            v.clear();
            flag = flag ^ 1;
        }
        return res;
        
    }
};
