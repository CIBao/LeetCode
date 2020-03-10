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
    int findBottomLeftValue(TreeNode* root) {
       queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while(!q.empty()){
            int m = q.size();
            for(int i = 0; i < m; i++){
                auto x = q.front(); q.pop();
                if(i==0)res = x->val;
                if(x->left)q.push(x->left);
                if(x->right)q.push(x->right);
            }
        }
        return res;
    }
};
