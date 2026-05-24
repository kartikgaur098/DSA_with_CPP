class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) {
        int l = 0 ;
        int r = k ;

        int sum = 0 ;
        for(int i = 0 ; i < k ; i++){
            sum = sum + nums[i] ;
        }

        int count =  0 ;
        if((sum/k)>= threshold){
            count++ ;
        }

        while(r<nums.size()){
            sum = sum - nums[l];
            sum = sum + nums[r];

            if((sum/k)>= threshold){
            count++ ;
        }

        l++ ;
        r++ ;
        }
        
       return count ;
    }
};