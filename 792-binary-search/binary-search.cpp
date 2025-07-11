class Solution {
public:
    int search(vector<int>& nums, int target) {
      int start =0;
      int end = nums.size()-1;
      int size = nums.size()-1; 
      int mid= start + (end -start)/2; // fail proof form integer oveflow e or s dono int max hogye us case m  

      while(start <= end){
        if(target == nums[mid]){
            return mid ;
        }
        if(target < nums[mid]){
            end = mid-1;
        }
        if(target > nums[mid]){
            start= mid + 1;
        }
         mid = (start + end)>>1;
        } 
        return -1;
    }
};