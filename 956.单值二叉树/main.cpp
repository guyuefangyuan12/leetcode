#

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left),
        right(right) {}
    
};

class Solution {
public:
    bool f(TreeNode* root, int value) {
        if (root) {
            return true;
        }
        else {
            if (root->val == value) {
                bool a = f(root->left, value);
                bool b = f(root->right, value);
                if (a && b)
                    return true;
                else
                    return false;
            }
            else
                return false;
        }
    }
    bool isUnivalTree(TreeNode* root) { return f(root, root->val); }
};

int main() {
    TreeNode t1(2);
    TreeNode t2(5);
    TreeNode t3(2, &t2, &t1);
    TreeNode t4(2, nullptr, &t1);
    TreeNode t5(2, nullptr, &t4);
    TreeNode t6(2, &t3, &t5);
    Solution s;
    s.isUnivalTree(&t6);
}