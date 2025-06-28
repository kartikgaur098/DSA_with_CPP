/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        // Base case: if tree is empty
        if (root == nullptr) return 0;

        // Find leftmost depth and rightmost depth
        int leftDepth = getLeftDepth(root);
        int rightDepth = getRightDepth(root);

        // If both depths are equal, it's a perfect tree
        if (leftDepth == rightDepth) {
            // Total nodes in perfect binary tree = 2^depth - 1
            return (1 << leftDepth) - 1;
        }

        // Otherwise, recursively count left and right
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    // Helper to calculate depth by going left
    int getLeftDepth(TreeNode* node) {
        int depth = 0;
        while (node) {
            node = node->left;
            depth++;
        }
        return depth;
    }

    // Helper to calculate depth by going right
    int getRightDepth(TreeNode* node) {
        int depth = 0;
        while (node) {
            node = node->right;
            depth++;
        }
        return depth;
    }
};
