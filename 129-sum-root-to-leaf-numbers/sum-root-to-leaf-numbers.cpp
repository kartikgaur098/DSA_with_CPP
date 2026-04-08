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
    void solve(TreeNode * root , vector<int> &nums , int oldnumber){
        if(root == NULL) return ;
        
        
            int newnumber = oldnumber * 10 + root->val; 
        
            oldnumber= newnumber;
            if(root->right == NULL && root->left == NULL)
                  nums.push_back(newnumber);
        
        solve(root->left , nums , oldnumber);
        solve(root->right , nums , oldnumber);

    }
    int sumNumbers(TreeNode* root) {
        vector<int> nums ;
        int oldnumber = 0 ;
        solve(root , nums , oldnumber);
        int sum = 0 ;
        for(int i=0 ; i< nums.size() ; i++){
            sum = sum + nums[i];
        }
        return sum ;
    }
};