//hyunji.erica
//103. Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        bool isLtoR = true;
        
        if(root == nullptr)
            return ans;
        
        q.push(root);
        
        while(!q.empty()){
            int level_size = q.size();
            vector<int> cur_level(level_size, 0);
            int index;
            for(int i = 0; i<level_size; i++){
                TreeNode* node = q.front();
                q.pop();
                
                if(isLtoR) index = i;
                else index = level_size - i - 1;
                
                cur_level[index] = node->val;
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(cur_level);
            isLtoR = !isLtoR;
        }
        return ans;
    }
};
