class Solution {
public:
    void dfs(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& result) {
        if (!root) return;

        path.push_back(root->val);
        targetSum -= root->val;

        // If it's a leaf node and sum is matched
        if (!root->left && !root->right && targetSum == 0) {
            result.push_back(path);
        }

        // Recur for left and right subtrees
        dfs(root->left, targetSum, path, result);
        dfs(root->right, targetSum, path, result);

        // Backtrack: remove last element before going up
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(root, targetSum, path, result);
        return result;
    }
};
