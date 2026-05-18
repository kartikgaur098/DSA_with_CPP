class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        vector<int> PS(n, 0);

        PS[0] = nums[0];
        for (int i = 1; i < n; i++) {
            PS[i] = PS[i - 1] + nums[i];
        }

        unordered_map<int, int> mp;

        for (int j = 0; j < n; j++) {

            if (PS[j] == k)
                count++;
            int val = PS[j] - k;

            if (mp.find(val) != mp.end()) {
                count = count+  mp[val];
                
            }

             mp[PS[j]]++;
        }
        return count;
    }
};