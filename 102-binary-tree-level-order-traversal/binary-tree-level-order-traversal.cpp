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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans ;
        if(root == NULL){
            return ans;
        }
        queue<TreeNode*> q ;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
                 vector<int> path ;
            for(int i = 0 ; i < size ; i++){
                TreeNode* element = q.front() ;
                q.pop();
                path.push_back(element->val);

                if(element->left != NULL)
                q.push(element->left);

                if(element->right != NULL)
                q.push(element->right);
            }
            ans.push_back(path);
        } 

        return ans ;
    }
};