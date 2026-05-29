class Solution {
public:

    void subSet1(int i , vector<int>& nums ,  vector<int> &ans,  vector<vector<int>> &allSubsets ){
        
        if( i  == nums.size()){
            allSubsets.push_back(ans);
            return ;
        }

        ans.push_back(nums[i]);
        subSet1(i+1 , nums  , ans,allSubsets );

        ans.pop_back();
        subSet1(i+1 , nums  , ans,allSubsets );
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets ;
        vector<int> ans ;

        subSet1( 0, nums , ans , allSubsets);
        return allSubsets;
    }
};