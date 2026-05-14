class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int , int> mp ;
        int ans=0 ;
        for(int num : nums){
            ans = ans + mp[num];
            mp[num]++ ;

        }
        return ans ;
    }
};