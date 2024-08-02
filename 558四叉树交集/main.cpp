#include<iostream>
using namespace std;
//暴力匹配，没考虑当有叶子节点时，可以简化运算。
class Node {
public:
	bool val;
	bool isLeaf;
	Node* topLeft;
	Node* topRight;
	Node* bottomLeft;
	Node* bottomRight;

	Node() {
		val = false;
		isLeaf = false;
		topLeft = NULL;
		topRight = NULL;
		bottomLeft = NULL;
		bottomRight = NULL;
	}

	Node(bool _val, bool _isLeaf) {
		val = _val;
		isLeaf = _isLeaf;
		topLeft = NULL;
		topRight = NULL;
		bottomLeft = NULL;
		bottomRight = NULL;
	}

	Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
		val = _val;
		isLeaf = _isLeaf;
		topLeft = _topLeft;
		topRight = _topRight;
		bottomLeft = _bottomLeft;
		bottomRight = _bottomRight;
	}
};

class Solution {
public:
	Node* intersect(Node* quadTree1, Node* quadTree2) {
		Node* p = new(Node);
		if (quadTree1->isLeaf) {
			if (quadTree2->isLeaf) {
				p->val = (quadTree1->val || quadTree2->val);
				p->isLeaf = true;
			}
			else {
				p->topLeft = intersect(quadTree1, quadTree2->topLeft);
				p->topRight = intersect(quadTree1, quadTree2->topRight);
				p->bottomLeft = intersect(quadTree1, quadTree2->bottomLeft);
				p->bottomRight = intersect(quadTree1, quadTree2->bottomRight);
				if (p->bottomLeft->isLeaf && p->bottomRight->isLeaf && p->topLeft->isLeaf && p->topRight->isLeaf) {
					if ((p->bottomLeft->val || p->bottomRight->val || p->topLeft->val || p->topRight->val) == p->bottomLeft->val && (p->bottomLeft->val && p->bottomRight->val && p->topLeft->val && p->topRight->val) == p->bottomLeft->val) {
						p->isLeaf = true;
						p->val = p->bottomLeft->val;
						p->topLeft = NULL;
						p->topRight = NULL;
						p->bottomLeft = NULL;
						p->bottomRight = NULL;
					}
					else {
						p->isLeaf = false;
					}
				}

				else {
					p->isLeaf = false;
				}

			}
		}
		else {
			if (quadTree2->isLeaf) {
				p->topLeft = intersect(quadTree1->topLeft, quadTree2);
				p->topRight = intersect(quadTree1->topRight, quadTree2);
				p->bottomLeft = intersect(quadTree1->bottomLeft, quadTree2);
				p->bottomRight = intersect(quadTree1->bottomRight, quadTree2);

				if (p->bottomLeft->isLeaf && p->bottomRight->isLeaf && p->topLeft->isLeaf && p->topRight->isLeaf) {
					if ((p->bottomLeft->val || p->bottomRight->val || p->topLeft->val || p->topRight->val) == p->bottomLeft->val && (p->bottomLeft->val && p->bottomRight->val && p->topLeft->val && p->topRight->val) == p->bottomLeft->val) {
						p->isLeaf = true;
						p->val = p->bottomLeft->val;
						p->topLeft = NULL;
						p->topRight = NULL;
						p->bottomLeft = NULL;
						p->bottomRight = NULL;
					}
					else {
						p->isLeaf = false;
					}
				}

				else {
					p->isLeaf = false;
				}
			}
			else {
				p->topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
				p->topRight = intersect(quadTree1->topRight, quadTree2->topRight);
				p->bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
				p->bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
				if (p->bottomLeft->isLeaf && p->bottomRight->isLeaf && p->topLeft->isLeaf && p->topRight->isLeaf) {
					if ((p->bottomLeft->val || p->bottomRight->val || p->topLeft->val || p->topRight->val) == p->bottomLeft->val && (p->bottomLeft->val && p->bottomRight->val && p->topLeft->val && p->topRight->val) == p->bottomLeft->val) {
						p->isLeaf = true;
						p->val = p->bottomLeft->val;
						p->topLeft = NULL;
						p->topRight = NULL;
						p->bottomLeft = NULL;
						p->bottomRight = NULL;
					}
					else {
						p->isLeaf = false;
					}
				}

				else {
					p->isLeaf = false;
				}
			}
		}
		return p;
	}
};


int main() {
	Node a(true, true);
	Node b(false, true);
	Node temp1(true, false, &b, &a, &b, &b);
	Node temp2(true, false, &b, &a, &b, &a);
	Node temp3(true, false, &a, &a, &b, &b);
	Node a1(true, false, &a, &temp1, &temp2, &temp3);
	Node temp4(true, false, &b, &b, &a, &a);
	Node temp5(true, false, &a, &b, &b, &a);
	Node a2(true, false, &a, &temp3, &temp4, &temp5);
	Node temp6(true, false, &b, &b, &a, &b);
	Node temp7(true, false, &a, &b, &a, &a);
	Node temp8(true, false, &a, &a, &b, &a);
	Node a3(true, false, &a, &temp6, &temp7, &temp8);
	Node a4(true, false, &b, &temp8, &temp3, &temp6);
	Node quadTree1(true, false, &a1, &a2, &a3, &a4);
	Node temp9(true, false, &b, &b, &b, &a);
	Node b1(true, false, &temp3, &temp1, &temp9, &temp3);
	Node temp10(true, false, &b, &a, &b, &a);
	Node b2(true, false, &temp10, &a, &b, &temp4);
	Node temp11(true, false, &a, &a, &a, &b);
	Node b3(true, false, &a, &temp7, &temp3, &temp11);
	Node b4(true, false, &temp2, &temp1, &b, &temp9);
	Node quadTree2(true, false, &b1, &b2, &b3, &b4);
	Solution s;
	auto p = s.intersect(&quadTree1, &quadTree2);
}