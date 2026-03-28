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
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long maxWidth = 0 ;
        if(root == NULL){
            return maxWidth ;
        }
        queue<pair<TreeNode * , unsigned long long>> q;
        q.push({root ,  0}) ;

        while(q.size() > 0){
            unsigned long long currLevelSize = q.size();
            unsigned long long startIndex = q.front().second ;
            unsigned long long endIndex = q.back().second ;
            unsigned long long updatedMaxwidth = endIndex - startIndex + 1 ;
            maxWidth = max(maxWidth , updatedMaxwidth);
            for(unsigned long long i = 0 ; i < currLevelSize ; i++){
                auto front = q.front();
                q.pop();

                if(front.first->left){
                    q.push({front.first->left , 2*front.second+1});
                }
                if(front.first->right){
                    q.push({front.first->right , 2*front.second+2 });
                }
            }
        }
        return maxWidth;
    }
};