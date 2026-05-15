class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> map ;
        for(int i = 0 ; i < nums.size() ; i++){
            int x = target - nums[i] ;
            if(map.count(x)){
                return {map[x] , i} ;
            }
            map[nums[i]] = i ;
        }
        return {};
    }
};