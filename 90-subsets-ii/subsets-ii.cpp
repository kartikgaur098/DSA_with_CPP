class Solution {
public:
    void subSet1(int i , vector<int>& nums ,  vector<int> &ans,  vector<vector<int>> &allSubsets ){ 
        if(i == nums.size()){
            allSubsets.push_back(ans);
            return ;
        }

        ans.push_back(nums[i]);
        subSet1(i+1 , nums  , ans,allSubsets );

        int index = i+1 ;

        while(index < nums.size() && nums[index] == nums[index-1]){
            index++ ;
        }

        ans.pop_back();
        subSet1(index , nums  , ans,allSubsets );
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> allSubsets ;
        vector<int> ans ;

        subSet1( 0, nums , ans , allSubsets);
        return allSubsets;
    }
};