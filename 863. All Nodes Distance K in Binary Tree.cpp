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
    vector<int> res;
    unordered_map<TreeNode*, TreeNode*> p;
    set<TreeNode*> vis;
    
    void find(TreeNode* root){
        if(root==NULL) {p[root] = NULL;return;}
        if(root->left){
            p[root->left] = root; find(root->left);
        }
        if(root->right){
            p[root->right] = root; find(root->right);
        }
        
    }
    
    void DFS(TreeNode* node, int K){
        if(vis.count(node)>0)return;
        vis.insert(node);
        if(K==0){
            if(node) res.push_back(node->val);
            return;
        }
        if(node->left)DFS(node->left, K-1);
        if(node->right)DFS(node->right, K-1);
        if(p[node] != NULL) DFS(p[node], K-1);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        find(root);
        DFS(target, K);
        return res;
    }
};
