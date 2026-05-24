class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
          
            
            int sum = 0 ;
            for(int i = 0 ; i < k  ; i++){
                sum = sum + nums[i];
            }

            int maxSum = sum ;

            int l = 0 ;
            int r = k ;
            while(r<nums.size()){
                sum = sum - nums[l] ;
                sum = sum + nums[r] ;
                l++ ;
                r++ ;
                maxSum = max(sum , maxSum);
            }
        return (double)maxSum/k;
    }
};