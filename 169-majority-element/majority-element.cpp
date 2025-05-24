class Solution{
public:
    int majorityElement(vector <int> &nums){
        int value=nums[0];
        int count=1;
        for(int i=0 ;i<nums.size(); i++){
            if(nums[i]==value)
            count++;
            else
            count--;
            if(count==0){
                value=nums[i];
                count=count+1;
            }
        }
         return value;
    }
};