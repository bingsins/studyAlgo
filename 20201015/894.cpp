#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct TreeNode 
{
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
	set<string> m_sStr;
	string m_strTemp;
	TreeNode* CopyTree(TreeNode* root)
	{
		TreeNode* node = new TreeNode(0);
		m_strTemp.push_back('1');

		if (root->left != nullptr)
			node->left = CopyTree(root->left);
		else
			m_strTemp.push_back('0');

		if (root->right != nullptr)
			node->right = CopyTree(root->right);
		else
			m_strTemp.push_back('0');

		return node;
	}

	void InsertLeafNode(TreeNode* root, TreeNode* node, vector<TreeNode*> &vDP)
	{
		if (node->left == nullptr || node->right == nullptr)
		{
			node->left = new TreeNode(0);
			node->right = new TreeNode(0);
			
			m_strTemp = "";
			TreeNode* pushTree = CopyTree(root);

			if (m_sStr.insert(m_strTemp).second != false)
				vDP.push_back(pushTree);

			node->left = nullptr;
			node->right = nullptr;
		}
		else
		{
			InsertLeafNode(root, node->right, vDP);
			InsertLeafNode(root, node->left, vDP);
		}
	}

	vector<TreeNode*> allPossibleFBT(int N)
	{
		if (N % 2 == 0)
		{
			return {};
		}

		vector<vector<TreeNode*>> vDP;
		vDP.resize(N + 1);
		
		TreeNode* root = new TreeNode(0);
		vDP[1].push_back(root);
		if (N == 1)
		{
			return vDP[1];
		}
		
		root->left = new TreeNode(0);
		root->right = new TreeNode(0);
		vDP[3].push_back(root);
		if (N == 3)
		{
			return vDP[3];
		}

		for (int i = 5; i <= N; i = i + 2)
		{
			m_sStr.clear();

			for (TreeNode* root : vDP[i - 2])
			{
				InsertLeafNode(root, root, vDP[i]);
			}
		}
		
		return vDP[N];
	}
};

void main()
{
	Solution *solution = new Solution();
	
	solution->allPossibleFBT(7);

	delete solution;
	system("pause");
}

