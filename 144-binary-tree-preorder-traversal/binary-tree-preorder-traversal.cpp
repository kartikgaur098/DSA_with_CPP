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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result ;
        if(root == NULL){
            return result ;
        }

        stack <TreeNode *> s ;
        s.push(root);

        while(!s.empty()){
            TreeNode * peek = s.top();
            s.pop();

            result.push_back(peek->val);

           if(peek -> right != NULL) s.push(peek->right) ;
           if(peek->left != NULL) s.push(peek->left) ;
        }

    return result ;


    }
};