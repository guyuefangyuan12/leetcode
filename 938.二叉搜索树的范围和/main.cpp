# include<vector>
#include<functional>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	int rangeSumBST(TreeNode* root, int low, int high)
	{
		int sum = 0;
		function<void(TreeNode* root)> dfs = [&](TreeNode* root)
			{
				if (root != nullptr) 
				{
					if (root->val >= low && root->val <= high) 
					{
						sum += root->val;
					}
					dfs(root->left);
					dfs(root->right);
				}
			};
		dfs(root);
		return sum;
	}
};