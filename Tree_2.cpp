#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        return (left->val == right->val) && isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
};

TreeNode* createTreeFromArray(const std::vector<int>& nodes, int index) {
    if (index >= nodes.size() || nodes[index] == -1) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(nodes[index]);
    root->left = createTreeFromArray(nodes, 2 * index + 1);
    root->right = createTreeFromArray(nodes, 2 * index + 2);

    return root;
}

int main() {
    Solution solution;

    std::vector<int> nodes1 = { 1, 2, 2, 3, 4, 4, 3 };
    TreeNode* root1 = createTreeFromArray(nodes1, 0);
    std::cout << std::boolalpha << solution.isSymmetric(root1) << std::endl;

    std::vector<int> nodes2 = { 1, 2, 2, -1, 3, -1, 3 };
    TreeNode* root2 = createTreeFromArray(nodes2, 0);
    std::cout << std::boolalpha << solution.isSymmetric(root2) << std::endl;

    std::vector<int> nodes3 = { 1, 2, 1 };
    TreeNode* root3 = createTreeFromArray(nodes3, 0);
    std::cout << std::boolalpha << solution.isSymmetric(root3) << std::endl;

    return 0;
}
