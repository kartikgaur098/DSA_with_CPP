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
    int minDepth(TreeNode* root) {
       if(root == NULL){
        return 0 ;
       } 
       int lh = minDepth(root->left);
       int rh = minDepth(root->right);
       int minHeight;
       if(lh!=NULL && rh!= NULL){
      minHeight = min(lh , rh)+ 1;
       }else if(rh != NULL && lh == NULL){
         minHeight = rh+1 ;
       }else if(rh == NULL && lh != NULL){
        minHeight = lh+1;
       }
       return minHeight;
    }
};