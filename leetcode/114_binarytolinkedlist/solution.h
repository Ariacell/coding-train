// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  void flatten(TreeNode* root) {
    TreeNode* prev = nullptr;
    flattenTree(root, prev);
  }

 private:
  void flattenTree(TreeNode* node, TreeNode*& prev) {
    if (!node) return;

    flattenTree(node->right, prev);
    flattenTree(node->left, prev);

    node->right = prev;
    node->left = nullptr;
    prev = node;
  }
};