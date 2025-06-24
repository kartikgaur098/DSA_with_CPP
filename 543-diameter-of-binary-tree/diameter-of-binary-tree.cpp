/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int getHeight(TreeNode* root) {
        if (root == NULL)
            return 0;
        int right = getHeight(root->right);
        int left = getHeight(root->left);
        int height = max(right, left);
        int maxHeight = height + 1;

        return maxHeight;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;

        int option1 = diameterOfBinaryTree(root->left);
        int option2 = diameterOfBinaryTree(root->right);
        int option3 = getHeight(root->left) + getHeight(root->right);
        int dia = max(option1, max(option2, option3));
        return dia;
    }
};