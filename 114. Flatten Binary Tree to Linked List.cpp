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
    TreeNode* flat(TreeNode* root){
        if(root==NULL)return NULL;
        if(root->left==NULL && root->right==NULL)return root;
        TreeNode* l = flat(root->left);
        TreeNode* r = flat(root->right);
        auto tmp = l;
        root->left = NULL;
        if(tmp==NULL) return root;
        else{
            while(tmp->right!=NULL)tmp = tmp->right;
            tmp->right = r;
        } 
        
        root->right = l;
        return root;
    }
    void flatten(TreeNode* root) {
        flat(root);
    }
};
