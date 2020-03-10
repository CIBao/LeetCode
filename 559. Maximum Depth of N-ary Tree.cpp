/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        int m = 0;
        helper(root,0, m);
        return m;
    }
    
    void helper(Node* root, int d, int& m){
        if(root==NULL) {
            m = max(m, d);
            return;
        }
        m = max(m, d+1);
        for(auto n: root->children){
            helper(n, d+1, m);
        }
    }
};
