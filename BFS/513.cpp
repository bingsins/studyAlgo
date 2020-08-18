#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:

	int findBottomLeftValue(TreeNode* root) 
	{
		queue<TreeNode*> q;
		queue<int> qDepth;

		int nLeftmost = root->val;
		int nLeftmostDepth = 1;

		q.push(root);
		qDepth.push(nLeftmostDepth);

		while (q.empty() != true)
		{
			TreeNode* node = q.front();
			int nDepth = qDepth.front();

			q.pop();
			qDepth.pop();
			
			if (nDepth > nLeftmostDepth)
			{
				nLeftmost = node->val;
				nLeftmostDepth = nDepth;
			}

			if (node->left == nullptr && node->right == nullptr)
			{
				continue;
			}
			else
			{
				nDepth++;

				if (node->left != nullptr)
				{
					q.push(node->left);
					qDepth.push(nDepth);
				}

				if (node->right != nullptr)
				{
					q.push(node->right);
					qDepth.push(nDepth);
				}
			}
		}
		
		return nLeftmost;
	}
};

void main()
{
	Solution *solution = new Solution();

	TreeNode* root;

	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(3);
	TreeNode node4(4);
	TreeNode node5(5);
	TreeNode node6(6);
	TreeNode node7(7);
	TreeNode node8(8);
	TreeNode node9(9);

	root = &node1;

	node1.left	= &node2;
	node1.right = &node3;
	node2.left	= &node4;
	node3.left	= &node5;
	node3.right = &node6;
	node5.left	= &node7;

 	int nResult = solution->findBottomLeftValue(root);
 
 	cout << "Result: " << nResult << endl;

	delete solution;
	system("pause");
}