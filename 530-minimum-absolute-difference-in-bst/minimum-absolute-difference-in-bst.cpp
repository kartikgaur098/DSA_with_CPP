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
    
    void storeinorder(TreeNode * root , vector<int> &nums){
        if(root == NULL) return ;

        storeinorder(root->left , nums);
        nums.push_back(root->val);
        storeinorder(root->right , nums);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> nums ;
        storeinorder(root , nums);
           int curr =  INT_MAX;
        for(int i = 0 ;i<nums.size()-1 ; i++){
            int temp = nums[i+1] - nums[i];
            curr = min(curr , temp);
        }

        return curr ;
    }
};