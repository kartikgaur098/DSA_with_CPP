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

    int getHeight(TreeNode * root){
        if(root== NULL){
            return 0;
        }
        int lh = getHeight(root->left);
        int rh= getHeight(root->right);

        int height = max(lh , rh)+ 1;
        return height ;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true ;
        }

        // Now check for curr node 
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        int absdiff = abs(lh - rh);
        bool status;
        if(absdiff<=1){
            status = true; 
        }
        else {
            status = false ;
        }

        int leftstatus = isBalanced(root->left);
        int rightstatus = isBalanced(root->right);

        if(status && leftstatus && rightstatus){
            return true;
        }else{
            return false ;
        }
    }
};