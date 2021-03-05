#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <stack>

using namespace std;

// Definition for a Node.
class Node 
{
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val)
	{
		val = _val;
	}

	Node(int _val, vector<Node*> _children) 
	{
		val = _val;
		children = _children;
	}
};

class Solution 
{
public:
	int nMaxDepth = 0;
	int nDepth = 0;

	int maxDepth(Node* root)
	{
		if (root == NULL)
			return nMaxDepth;

		nDepth++;

		int nSize = root->children.size();
		for (int i = 0; i < nSize; i++)
		{
			maxDepth(root->children[i]);
			nDepth--;
		}

		nMaxDepth = max(nDepth, nMaxDepth);
		return nMaxDepth;
	}
};

void main()
{
	Solution *solution = new Solution();

	Node* root = { NULL };

	Node temp1;	temp1.val = 1;
	root = &temp1;

	Node temp3; temp3.val = 3;
	root->children.push_back(&temp3);
	Node temp2; temp2.val = 2;
	root->children.push_back(&temp2);
	Node temp4; temp4.val = 4;
	root->children.push_back(&temp4);

	Node temp5; temp5.val = 5;
	root->children[0]->children.push_back(&temp5);
	Node temp6; temp6.val = 6;
	root->children[0]->children.push_back(&temp6);
		
	int nResult = solution->maxDepth(root);

	cout << "Result: " << nResult << endl;

	delete solution;
	system("pause");
}