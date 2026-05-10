class Solution {
public:

    static bool cmp( string a , string b){
       return a+b > b+a ;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> arr ;
        string ans = "";
        for(int i = 0 ; i<nums.size() ; i++){
            arr.push_back(to_string(nums[i])); 
        }

        sort(arr.begin() , arr.end() , cmp) ;

        for(int i = 0 ; i<arr.size() ; i++){
            ans = ans + arr[i] ; 
        }

        if(ans[0] == '0') {
            return "0" ;
        }
        return ans ;
    }
};