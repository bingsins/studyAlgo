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
   vector<TreeNode*> nodes;
    void inorderTraverse(TreeNode* root) {
        if(!root) return;
        if(root->left) inorderTraverse(root->left);
        nodes.push_back(root);
        if(root->right) inorderTraverse(root->right);
    }
    
    TreeNode* construct(int l, int r) {
        if(l>=r) return NULL;
        int mid = l + (r-l)/2;
        TreeNode* node = nodes[mid];
        node->left = construct(l,mid);
        node->right = construct(mid+1,r);
        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        inorderTraverse(root);
        return construct(0,nodes.size());
    }
    
};
