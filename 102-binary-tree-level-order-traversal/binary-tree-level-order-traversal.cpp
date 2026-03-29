class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL)
            return result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> ans(size);

            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();

                ans[i] = front->val;
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
            result.push_back(ans);
        }
        return result;
    }
}
;