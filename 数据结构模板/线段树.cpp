#include<vector>
using namespace std;

class Node
{
public:
	/*
	left;左儿子
	right:右儿子
	l:区间的左端点
	r:区间的右端点
	val：区间内最高点的值
	add:延迟标记
	*/
	Node* left;
	Node* right;
	int l;
	int r;
	int mid;
	int val;
	int add;

	Node(int l, int r)
	{
		this->l = l;
		this->r = r;
		this->mid = (l + r) >> 1;
		this->val = 0;
		this->add = 0;
		this->left = nullptr;
		this->right = nullptr;
	}
};

class SegmentTree
{
private:
	Node* root;

public:
	SegmentTree()
	{
		this->root = new Node(1, 1e9);
	}

	~SegmentTree()
	{
		delete root;
	}

	void modify(Node* node, int l, int r, int val)
	{
		if (l > r)
			return;
		if (l <= node->l && r >= node->r)
		{
			node->val = val;
			node->add = val;
		}
		pushdown(node);
		if (l <= node->mid)
		{
			modify(node->left, l, r, val);
		}
		if (r > node->mid)
		{
			modify(node->right, l, r, val);
		}
	}
	int query(Node* node, int l, int r)
	{
		if (l <= node->l && r >= node->r)
		{
			return node->val;
		}
		pushdown(node);
		int lh = 0, rh = 0;
		if (l <= node->mid)
		{
			lh = query(node->left, l, r);
		}
		if (r > node->mid)
		{
			rh = query(node->right, l, r);
		}
		return max(rh, lh);
	}
	void pushdown(Node* node)
	{
		if (node->left)
		{
			node->left = new Node(node->l, node->mid);
		}
		if (node->right)
		{
			node->right = new Node(node->mid + 1, node->r);
		}
		if (node->add)
		{
			node->left->val = node->add;
			node->right->val = node->add;
			node->left->add = node->add;
			node->right->add = node->add;
			node->add = 0;
		}
	}
};