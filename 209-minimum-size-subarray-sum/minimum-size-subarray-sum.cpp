class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n= nums.size();
        int left=0;
        int minLength = INT_MAX;
        int sum =0;
         for(int right = 0 ; right<n;right++){
             sum = sum+ nums[right];

              while(sum>=target){
                minLength= min(minLength , right - left+1);
                sum = sum- nums[left];
                left++;
              }

         }
         return (minLength==INT_MAX)?0:minLength;
    }
};