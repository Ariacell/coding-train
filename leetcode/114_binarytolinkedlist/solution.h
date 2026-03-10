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
        //use a stack to dfs this tree
        
        flattenTree(root, nullptr);
        
    }

    void flattenTree(TreeNode* node, TreeNode* prev) {
    if (!node) return;

    flattenTree(node->left, prev);
    flattenTree(node->right, prev);


        if (node->left != nullptr) {
            // Store the right subtree
            TreeNode* temp = node->right;

            // Move the left subtree to the right
            node->right = node->left;
            node->left = nullptr;

            // Find the rightmost node of the new right subtree
            TreeNode* current = node->right;
            while (current->right != nullptr) {
                current = current->right;
            }

            // Connect the right subtree
            current->right = temp;
        }
    }
};