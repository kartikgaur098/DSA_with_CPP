class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int x : nums) {
            mp[x]++;
        }
        for(auto &it : mp) {
            if(it.second > n/2)
                return it.first;
        }
        return -1;
    }
};