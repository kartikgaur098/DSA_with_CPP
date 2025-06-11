class Solution {
    public:
    int removeElement(vector <int> &nums , int val){
       int  validElementKaIndex=0;
       int j = nums.size();
        for(int i=0;i<j;i++){
            if(nums[i]!=val){
                nums[validElementKaIndex]=nums[i];
                validElementKaIndex++;
            }
        }
        return validElementKaIndex;
    }
};



// ques ko chahiye inplace value ko remove krdein order maintain krne ki jrurat  nhi hai or remove k bad kitne element bche unka number chaiye

// ans m ye soch skte hain ki koi nya variable lelo jisme valid number ka index ajae 
// fr ek chhla lo loop last tk jisme condition check krlo ki number shi h ya  nhi agr shi number hua to us number ko nye wale index pr put krlo or index bdha do 
