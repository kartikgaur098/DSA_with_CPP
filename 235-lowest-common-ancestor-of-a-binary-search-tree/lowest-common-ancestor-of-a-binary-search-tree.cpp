/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL ;
        }

       if(p->val > root->val && q->val > root->val){
         TreeNode * right = lowestCommonAncestor(root->right , p , q);
         if(right != NULL){
            return right ;
         }
       }

       if(p->val < root->val && q->val < root->val){
         TreeNode * left = lowestCommonAncestor(root->left , p , q);
         if(left != NULL){
            return left ;
         }
       }

        return root  ;

        
    }
};