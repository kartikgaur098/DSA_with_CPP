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
    void storeInorder(TreeNode * root , vector<int> &inorder){
        if(root == NULL){
            return  ;
        }
        storeInorder(root->left , inorder);
        inorder.push_back(root->val);
        storeInorder(root->right , inorder);
    }
    bool checkTwoSum(TreeNode* root , vector<int> inorder , int target){
        int s = 0 ;
        int e = inorder.size()-1;

        while(s<e){
            int sum = inorder[s]+inorder[e];
            if(sum > target){
                e--;
            }else if(sum<target){
                s++;
            }else if(sum == target){
                return true ;
            }
        }
        return false ; 
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        storeInorder(root , inorder);
        bool ans = checkTwoSum(root, inorder , k);
        return ans ;
    }
};