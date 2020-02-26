
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
    int res = 0;
    void DFS(TreeNode* root, int h)
    {
        res = max(res, h);
        if(root->left!=nullptr)DFS(root->left, h+1);
        if(root->right!=nullptr)DFS(root->right, h+1);
    }
    int maxDepth(TreeNode* root) {
        if(root==nullptr)return 0;
        
        DFS(root, 1);
        return res;
    }
};
