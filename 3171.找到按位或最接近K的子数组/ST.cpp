#include<vector>
using namespace std;

class Node
{
public:
	int l;
	int r;
	int ans;
	Node* ln;
	Node* rn;
	Node(int left, int right) :l(left), r(right)
	{
		ans = 0;
		ln = nullptr;
		rn = nullptr;
	}
};
class ST
{
public:
	Node* root;
	Node* build(vector<int>& nums, int l, int r)
	{
		Node* n = new Node(l, r);
		if (l == r)
		{
			n->ans = nums[l];
		}
		else
		{
			int mid = (l + r) >> 1;
			n->ln = build(nums, l, mid);
			n->rn = build(nums, mid + 1, r);
			n->ans = n->ln->ans | n->rn->ans;
		}
		return n;
	}
	void buildroot(vector<int>& nums, int l, int r)
	{
		root = build(nums, l, r);
	}
	int query(Node* n, int left, int right)
	{
		int ans = 0;
		if (left <= n->l && right >= n->r)
		{
			ans |= n->ans;
			return ans;
		}
		int mid = (n->l + n->r) >> 1;
		if (left <= mid)
		{
			ans |= query(n->ln, left, right);
		}
		if (right >= mid + 1)
		{
			ans |= query(n->rn, left, right);
		}
		return ans;
	}
	int Query(int left, int right)
	{
		return query(root, left, right);
	}
};

class Solution
{
public:
	int minimumDifference(vector<int>& nums, int k)
	{
		int n = nums.size();
		ST s;
		s.buildroot(nums, 0, n - 1);
		vector<int> cnt(n, -1);
		int sum = 0;
		int diff = INT_MAX;
		for (int i = 0; i < n; i++)
		{
			int start;
			if (i == 0 || cnt[i - 1] == -2)
			{
				start = i;
				sum = 0;
			}
			else
			{
				start = cnt[i - 1];
				sum = s.Query(i, start - 1);
			}
			for (int j = start; j < n; j++)
			{
				sum |= nums[j];
				diff = min(diff, abs(sum - k));
				if (sum == k)
				{
					return 0;
				}
				if (sum > k)
				{
					if (j == i || j == i + 1)
					{
						cnt[i] = -2;
					}
					else
					{
						cnt[i] = j - 1;;
					}
					break;
				}
			}
			if (cnt[i] == (-1))
			{
				return diff;
			}
		}
		return diff;
	}
};

