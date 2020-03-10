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
    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL)return 0;
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int m = q.size();
            res = 0;
            for(int i = 0; i < m; i++){
                TreeNode* x = q.front();
                q.pop();
                res += x->val;
                if(x->left)q.push(x->left);
                if(x->right)q.push(x->right);
            }
        }
        return res;
    }
};
