//1123. Lowest Common Ancestor of Deepest Leaves
// See problem 865(Smallest Subtree with all the Deepest Nodes) for better understanding.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *ans;
    int max_depth = 0;
    
    int dfs(TreeNode* root, int depth){
        max_depth = max(max_depth, depth);
        if(root == nullptr) return depth;
        
        int left_depth = dfs(root->left, depth+1);
        int right_depth = dfs(root->right, depth+1);
        
        if(left_depth == max_depth && right_depth == max_depth)
            ans = root;
        
        return max(left_depth, right_depth);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};
