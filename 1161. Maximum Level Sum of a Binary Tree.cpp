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
    int maxLevelSum(TreeNode* root) {
        int maxlevel = -1, maxx = -1;
        queue<TreeNode*> Q;
        Q.push(root);
        int level = 0;
        while(!Q.empty()){
            int m = Q.size();
            level++;
            int tmp = 0;
            for (int i = 0; i < m; ++i) {
                auto x = Q.front(); Q.pop();
                tmp += x->val;
                if(x->left)Q.push(x->left);
                if(x->right)Q.push(x->right);
            }
            if(maxx < tmp){
                maxx = tmp;
                maxlevel = level;
            }
        }
        return maxlevel;

    }
};
