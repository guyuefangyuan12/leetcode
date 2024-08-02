#include<iostream>

 struct TreeNode {
	int val; 
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};

 class Solution {
 public:

	 TreeNode* find(TreeNode* tree, int value) {
		 TreeNode* p;
		 if (tree == NULL) {
			 return NULL;
		 }
		 else if (tree->val == value) {
			 return tree;
		 }
		 else {
			 p = find(tree->left, value);
			 if (p != NULL)
				 return p;
			 else return find(tree->right, value);
		 }
	 }

	 TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
		 return find(cloned, target->val);
	 }
 };

 int main() {

 }