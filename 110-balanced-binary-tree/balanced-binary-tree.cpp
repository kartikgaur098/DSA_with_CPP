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
   
    int Height(TreeNode* root , bool &isbalanced){
        if(root == NULL) return 0;
        int lh = Height(root->left , isbalanced);
        int rh = Height(root->right , isbalanced);

        int height  = abs(lh-rh);
        if(isbalanced == true && height > 1){
            isbalanced = false ;
        }
        return 1 + max(lh ,  rh) ;
    }
    bool isBalanced(TreeNode* root) {
        bool isbalanced = true ;
        int ans = Height(root  , isbalanced);
        return isbalanced ;
    }
};