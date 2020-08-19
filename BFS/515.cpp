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
     vector<int> largestValues(TreeNode* root) {
    vector<int> answer;
    if (root == NULL) return answer;
    queue<TreeNode*> Q;
    Q.push(root);

    while (!Q.empty()) {
        int size = Q.size();
        int maximum = INT_MIN;
        for (int i=0; i<size; i++) {
            TreeNode* rt = Q.front();
            Q.pop();
            maximum = max(maximum, rt->val);
            //cout<<rt->val;
            if (rt->left) Q.push(rt->left);
            if (rt->right) Q.push(rt->right);
        }
        answer.push_back(maximum);
    }
    return answer; 
    }
};