#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution {
public:
	int maxDepth(Node* root) {
		Node* p;
		int maxh;
		if (root == NULL)
			return 0;
		else {
			for (int i = 0; i < root->children.size(); i++) {
				p = root->children[i];
				if (p != NULL) {
					int h = maxDepth(p);
					if (maxh < h)
						maxh = h;
				}
				return maxh + 1;
			}
		}
	}
};