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
    int getMax(TreeNode* root){
        while(root->right != NULL){
            root = root->right;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return NULL;
        }

        if (root->val == key) {
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL ;
            } else if (root->left != NULL && root->right == NULL) {
                TreeNode* leftchild = root->left;
                root->left = NULL;
                delete root;
                return leftchild;
            } else if (root->right != NULL && root->left == NULL) {
                TreeNode* rightchild = root->right;
                root->right = NULL;
                delete root;
                return rightchild;
            } else if (root->right != NULL && root->left != NULL) {
                int maxValue = getMax(root->left);
                root->val = maxValue;
                root->left = deleteNode(root->left, maxValue);
                return root;
            }
        }
        else{
            if(root->val > key){
               root->left =  deleteNode(root->left , key);
            }else{
               root->right = deleteNode(root->right , key);
            }
        }
    return root ;
    }
};