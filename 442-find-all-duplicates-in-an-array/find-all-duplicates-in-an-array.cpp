class Solution {
public:
  vector<int> findDuplicates(vector<int>& nums) {
    unordered_map<int,int> mp;
    vector<int> ans;

    for(int x : nums){
        mp[x]++;
        if(mp[x] == 2){
            ans.push_back(x);
        }
    }
    return ans;
}
    };