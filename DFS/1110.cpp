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
    vector<TreeNode*> result;
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        //vector<TreeNode*> result; 
        dfs(root, to_delete);
        
        if(!(find(to_delete.begin(), to_delete.end(), root->val) != to_delete.end()))
            result.push_back(root);
        return result;
    }
    
private:
    TreeNode* dfs(TreeNode* root, vector<int>& to_delete){
        if(root == NULL )
            return root;
        if(root->left)
        root->left = dfs(root->left, to_delete);
        if(root->right)
        root->right = dfs(root->right, to_delete);
            
        if(find(to_delete.begin(), to_delete.end(), root->val) != to_delete.end()){
            if (root->left != NULL){
                   result.push_back(root->left);
                }
                if (root->right != NULL)
                {
                    result.push_back(root->right);
                }

                return NULL;
        }
            return root;
        
    }
};


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
    vector<TreeNode*> result;
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        //vector<TreeNode*> result; 
        set<int> set_to_delete(to_delete.begin(), to_delete.end());
        
        dfs(root, set_to_delete);
        
        if(set_to_delete.count(root->val) == 0)
            result.push_back(root);
        return result;
    }
    
private:
    TreeNode* dfs(TreeNode* root, set<int>& to_delete){
        
        if(root == NULL )
            return root;
        if(root->left){
            
                 root->left = dfs(root->left, to_delete);   
        }

        if(root->right){
                    root->right = dfs(root->right, to_delete);
        }

            
        if(to_delete.count(root->val) != 0){
        
            if (root->left != NULL){
                   result.push_back(root->left);
                }
                if (root->right != NULL)
                {
                    result.push_back(root->right);
                }

                return NULL;
        }
            return root;
        
    }
};

