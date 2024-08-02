#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution
{
	vector<int> nums;
	void dfs(TreeNode* root)
	{
		if (root != nullptr) 
		{
			if (root->left == nullptr)
			{
				if (root->right == nullptr)
				{
					nums.push_back(root->val);
				}
				else
				{
					dfs(root->right);
					nums.push_back(root->val);
				}
			}
			else
			{
				if (root->right == nullptr)
				{
					dfs(root->left);
					nums.push_back(root->val);
				}
				else
				{
					dfs(root->left);
					dfs(root->right);
					nums.push_back(root->val);
				}
			}
		}
	}
public:
	vector<int> postorderTraversal(TreeNode* root)
	{
		dfs(root);
		return nums;
	}
};