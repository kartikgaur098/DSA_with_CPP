class Solution {
public:
    int jump(vector<int>& nums) {
        int left = 0;
        int right = 0 ;
        int farthest = 0 ;
        int jumps = 0;

        while(right < nums.size() - 1){
            for(int  i = left ; i<=right ; i++ ){
            farthest = max(farthest , i+nums[i]);
            }
                left = right + 1;
                right = farthest ;
                jumps =  jumps+1 ;
        }
        return jumps ;
    }
};