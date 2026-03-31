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
        bool isMirror(TreeNode* p ,TreeNode* q){
            if(q == NULL && p == NULL){
                return true;
            }
            if(q!= NULL && p!=NULL){
                bool value = p->val == q->val;
                bool right = isMirror(p->left , q->right);
                bool left = isMirror(p->right , q->left);
                return value && left && right;
            }

            return false ;
        }
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->right , root->left);
    }
};