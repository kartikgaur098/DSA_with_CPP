class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0 ;
        for (int num : nums)
            mp[num]++;

        for (auto& it : mp) {
            if (it.second == 1)
                ans =  it.first;
        }

        return ans ;
    }
};