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

// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         int depth = 0 ; 
//         if(root  == NULL ) return 0;
//         int leftDepth = maxDepth(root->left);
//         int rightDepth = maxDepth(root->right);
//         return ( max(leftDepth, rightDepth) + 1);
        
//     }
// };

class Solution {
public:
    //TreeNode* answer;
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        //if(root  == NULL ) return root;

        TreeNode *answer = NULL;
        maxDepth(root, &answer);
        return answer;
        
    }
   int maxDepth(TreeNode* root,TreeNode **answer  ){
        int leftDepth=0, rightDepth=0;
        TreeNode *leftTree =NULL ,*rightTree=NULL;
       
       if(root  == NULL ) return 0;
       
       if (root->left)
         leftDepth = maxDepth(root->left, &leftTree);
       if (root->right)
         rightDepth = maxDepth(root->right, &rightTree);
       
       
       
        if (leftDepth > rightDepth) {
            *answer = leftTree;
        } else if (leftDepth < rightDepth) {
            *answer = rightTree;
        } else {
            *answer = root;
        }
        return ( max(leftDepth, rightDepth) + 1);
        
    }
};