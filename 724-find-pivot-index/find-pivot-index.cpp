class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int tsum = 0 ;
        
        for(int i = 0 ; i<nums.size() ; i++){
            tsum = tsum + nums[i];
        }

        int lsum= 0 ;
        for(int i = 0 ; i<nums.size() ;i++){
           
            tsum = tsum-nums[i] ;
            if(lsum == tsum){
               return i ;
            }
             lsum = lsum + nums[i];
        }
        return -1 ;
    }
};