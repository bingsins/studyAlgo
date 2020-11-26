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
    vector<vector<int>> result;
    vector<vector<int>> levelOrder(Node* root) {
        int depth = 0 ; 
        DFS(root,0);
    return result;
    }
    
    void DFS(Node* root, int depth) {
        if(!root)
            return;
        
        if (result.size() <= depth){ 
            result.push_back({});
        }
        result[depth].push_back(root->val);
        
        for(auto & item : root -> children)
         DFS(item, depth+1 );
    }
};