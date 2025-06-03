class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j=numbers.size()-1;
         while(i<j){
            int ans=numbers[i]+numbers[j];
            if(ans == target){
                return {i+1 , j+1};
            }
            if(ans> target){
                j--;
            }
            else{
                i++;
            }
        }
        return {} ;
    }
};