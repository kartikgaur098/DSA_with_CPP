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
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0 ;
        
        int leftSubtreeHeight= maxDepth(root -> left);
        int rightSubtreeHeight = maxDepth(root -> right);
        int height= max(leftSubtreeHeight , rightSubtreeHeight);
        int maxHeight = height +1 ;
        return maxHeight;
    }
};