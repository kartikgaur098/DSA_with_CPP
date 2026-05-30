class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, int i) {
        if (i >= nums.size()) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> st;

        for (int j = i; j < nums.size(); j++) {
            if (st.count(nums[j]))
                continue;
            st.insert(nums[j]);
            
            swap(nums[i], nums[j]);
            solve(nums, ans, i + 1);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int i = 0;
        solve(nums, ans, i);
        return ans;
    }
};