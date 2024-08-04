#include<functional>
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
	bool isSubtree(TreeNode* root, TreeNode* subRoot)
	{
		int flag = 0;
		function<bool(TreeNode*, TreeNode*)> dfs = [&](TreeNode* r, TreeNode* sub)->bool
			{
				if (r == nullptr)
				{
					if (sub == nullptr)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				else
				{
					if (sub == nullptr)
					{
						return false;
					}
					else
					{
						if (r->val == sub->val)
						{
							return dfs(r->left, sub->left) && dfs(r->right, sub->right);
						}
						else
						{
							return false;
						}
					}
				}
			};
		function<bool(TreeNode*)> f = [&](TreeNode* r)->bool
			{
				if (r != nullptr)
				{
					if (dfs(r, subRoot))
					{
						return true;
					}
					else
					{
						return f(r->left) || f(r->right);
					}
				}
				else
				{
					return false;
				}
			};
		return f(root);
	}
};