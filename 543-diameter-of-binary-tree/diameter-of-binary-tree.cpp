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
    int solve(TreeNode * root , int &d){
        if (root == NULL) return 0;
        
        int lh = solve(root->left , d);
        int rh = solve(root->right , d);

        int currd = lh + rh ;
        d = max(d , currd) ;
        return max(rh , lh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0 ;
        int ans = solve( root , d );
        return d ;
    }
};