#include<vector>
using namespace std;

class STNode
{
public:

	STNode* left;
	STNode* right;
	int l;
	int r;
	bool val;

	STNode(int l, int r, vector<int>& nums)
	{
		this->l = l;
		this->r = r;
		this->right = nullptr;
		this->left = nullptr;
		if (l + 1 == r)
		{
			if (nums[l] % 2 + nums[r] % 2 == 1)
			{
				this->val = true;
			}
			else
			{
				this->val = false;
			}
		}
		else
		{
			if (l == r)
			{
				this->val = true;
			}
			else
			{
				int mid = (l + r) >> 1;
				this->left = new STNode(l, mid, nums);
				this->right = new STNode(mid, r, nums);
				this->val = (this->left->val) && (this->right->val);
			}
		}
	}
	~STNode()
	{
		delete left;
		delete right;
	}
};
class ST
{
private:
	STNode* root;
public:
	ST(int l, int r, vector<int>& nums)
	{
		this->root = new STNode(l, r, nums);
	}
	~ST()
	{
		delete root;
	}

	bool query(STNode* node, int l, int r)
	{
		if (l == r)
		{
			return true;
		}
		if (l <= node->l && r >= node->r)
		{
			return node->val;
		}
		else
		{
			int mid = (node->l + node->r) >> 1;
			bool hl = true, hr = true;
			if (l < mid)
			{
				hl = query(node->left, l, r);
			}
			if (r > mid)
			{
				hr = query(node->right, l, r);
			}
			return hl && hr;
		}
	}
	bool query(int l, int r)
	{
		return query(root, l, r);
	}
};

class Solution
{
public:
	vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries)
	{
		int n = nums.size();
		ST s(0, n - 1, nums);
		n = queries.size();
		vector<bool> ans(n);
		for (int i = 0; i < n; i++)
		{
			ans[i] = s.query(queries[i][0], queries[i][1]);
		}
		return ans;
	}
};

int main()
{
	vector<int> nums = { 4,3,1,6 };
	vector<vector<int>> queries = { {0,2},{2,3} };
	Solution s;
	s.isArraySpecial(nums, queries);
}