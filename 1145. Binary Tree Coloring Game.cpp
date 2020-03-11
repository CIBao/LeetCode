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
    int left, right;
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        count(root, x);
        return max(max(left, right), n-1-left-right)>n/2;
    }
    
    int count(TreeNode* root, int x){
        if(root==NULL)return 0;
        int l = count(root->left, x);
        int r = count(root->right, x);
        if(root->val == x){
            left = l;
            right = r;
        }
        return l + r + 1;
    }
};
