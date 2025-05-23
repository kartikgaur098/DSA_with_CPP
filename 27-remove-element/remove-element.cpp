class Solution {
    public:
    int removeElement(vector <int> &nums , int val){
       int  k=0;
       int j = nums.size();
        for(int i=0;i<j;i++){
            if(nums[i]!=val){
                nums[k]=nums[i];
                k++;
            }
        }
        return k;
    }
};
