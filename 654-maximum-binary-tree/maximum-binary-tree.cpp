/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(vector<int>& nums, int s, int e) {
        if (s > e) {
            return NULL;
        }
        int index = s;
        for (int i = s; i <= e; i++) {
            if (nums[i] > nums[index]) {
                index = i;
            }
        }

        TreeNode* node = new TreeNode(nums[index]);
        node->left = solve(nums, s, index - 1);
        node->right = solve(nums, index + 1, e);

        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int e = nums.size() - 1;
        int s = 0;
        TreeNode* ans = solve(nums, s, e);
        return ans;
    }
};