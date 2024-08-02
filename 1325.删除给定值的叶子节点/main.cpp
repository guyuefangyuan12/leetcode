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
	TreeNode* removeLeafNodes(TreeNode* root, int target)
	{
		if (root->left == nullptr)
		{
			if (root->right == nullptr)
			{
				if (root->val == target)
				{
					root = nullptr;
				}
			}
			else
			{
				root->right=removeLeafNodes(root->right, target);
			}
		}
		else
		{
				root->left=removeLeafNodes(root->left, target);
			if (root->right != nullptr)
			{
				root->right=removeLeafNodes(root->right, target);
			}
		}
		if (root) 
		{
			if (root->left == nullptr && root->right == nullptr)
			{
				if (root->val == target)
				{
					root = nullptr;
				}
			}
		}
		return root;
	}
};

int main() {
	TreeNode t1(1);
	TreeNode t2(1);
	TreeNode t3(1, &t1, &t2);
	Solution s;
	s.removeLeafNodes(&t3, 1);
}
