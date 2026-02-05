#include <queue>
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 right(right) {}
 };

 class Tree {
  public:
   TreeNode* rootNode;
   Tree(int[] nodevalues) {
     TreeNode* root(nodeValues[0]);
     rootNode = root;
     std::queue<TreeNode*> treeNodes;
     treeNodes.push(root);

     for (int i = 1; i < nodevalues.size(); i++) {
       TreeNode* currentNode = treeNodes.front();
       treeNodes.pop();

       if (i < nodeValues.size()) {
         currentNode->left = TreeNode(nodevalues[i]);
         treeNodes.push(currentNode->left);
       }
       i += 1;
       if (i < nodeValues.size()) {
         currentNode->right = TreeNode(nodevalues[i]);
         treeNodes.push(currentNode->right);
       }
       i += 1;

     }
   }
 };
 
class Solution {
  public:
  bool isSymmetric(TreeNode* root) { return isSymmetricIterative(root);
   };

   bool isSymmetricIterative(TreeNode* root) {
     if ((root->left == nullptr) && (root->right == nullptr)) {
       return true;
     }

     std::queue<TreeNode*> tree_q;
     tree_q.push(root->left);
     tree_q.push(root->right);
     while (tree_q.size() > 0) {
       TreeNode* node_to_check_left = tree_q.front();
       tree_q.pop();
       TreeNode* node_to_check_right = tree_q.front();
       tree_q.pop();

       if ((node_to_check_left == nullptr) &&
           (node_to_check_right == nullptr)) {
         return true;
       }

       if (node_to_check_left == nullptr || node_to_check_right == nullptr) {
         return false;
       }

       if (node_to_check_left->val != node_to_check_right->val) {
         return false;
       }

       tree_q.push(node_to_check_left->left);
       tree_q.push(node_to_check_right->right);
       tree_q.push(node_to_check_left->right);
       tree_q.push(node_to_check_right->left);
     }

     return true;
   };


      bool isSymmetricRecursive(TreeNode* left, TreeNode* right) {
     if ((left == nullptr) && (right == nullptr)) {
       return true;
     }

    if (left == nullptr || right == nullptr) {
       return false;
     }

     if (left->val != right->val) {
       return false;
     }

     return isSymmetricRecursive(left->left, right->right) &&
            isSymmetricRecursive(left->right, right->left);
   };
 };