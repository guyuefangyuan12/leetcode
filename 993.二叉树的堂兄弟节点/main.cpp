#include<vector>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
	void DFS(TreeNode* root, vector<vector<int>>& depth)
	{
		if (root->left != nullptr)
		{
			depth[root->left->val][0] = depth[root->val][0] + 1;
			depth[root->left->val][1] = root->val;
			DFS(root->left, depth);
		}
		if (root->right != nullptr)
		{
			depth[root->right->val][0] = depth[root->val][0] + 1;
			depth[root->right->val][1] = root->val;
			DFS(root->right, depth);
		}
	}
	bool isCousins(TreeNode* root, int x, int y)
	{
		vector<vector<int>>depth(101, vector<int>(2, 0));
		DFS(root, depth);
		return depth[x][0] == depth[y][0] && depth[x][1] != depth[y][1];
	}
};