class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> PS(n, 0);
        PS[0] = nums[0];
        for(int i = 1; i < n; i++){
            PS[i] = PS[i-1] + nums[i];
        }

        unordered_map<int,int> mp;
        mp[0] = 1;   // IMPORTANT (added)
        int count = 0;
        for(int i = 0; i < n; i++){
            int rem = PS[i] % k;
            if(rem < 0) rem += k;   // IMPORTANT (negative fix)
            if(mp.find(rem) != mp.end()){
                count += mp[rem];
            }
            mp[rem]++;
        }

        return count;
    }
};