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
    map<TreeNode*, int> mp1, mp2;
    int DFS(TreeNode* root,  bool pre){
        if(pre && mp1.count(root)) return mp1[root];
        if(!pre && mp2.count(root)) return mp2[root];
        if(root == NULL) return 0;
        
        int l = DFS(root->left,false);
        int r = DFS(root->right,false);
       
        if(pre) return l+r;
        int l2 = DFS(root->left,true);
        int r2 = DFS(root->right, true);
        int m = max(l+r, root->val +l2+r2);
        if(pre) mp1[root] = m;
        else    mp2[root] = m;
        return m;
        
    }
    
    int rob(TreeNode* root) {
        return DFS(root,false);
    }
};
