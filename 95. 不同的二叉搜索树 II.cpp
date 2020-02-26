//看题解，卡特兰数，递归实现

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

    vector<TreeNode*> generateTrees(int s, int e){
        vector<TreeNode*> tmp;
        if(s>e)tmp.push_back(nullptr);
        
        for(int i = s; i<=e; i++){
            vector<TreeNode*> ltrees = generateTrees(s, i-1);
            vector<TreeNode*> rtrees = generateTrees(i+1, e);
            for(auto l: ltrees)
            for(auto r: rtrees){
                TreeNode* nd = new TreeNode(i);
                nd->left=l;
                nd->right=r;
                tmp.push_back(nd);
            }
        }
        return tmp;
    }

    vector<TreeNode*> generateTrees(int n) {
        if(n == 0){
            return vector<TreeNode*>();
        }
        return generateTrees(1, n);
        
    }
};
