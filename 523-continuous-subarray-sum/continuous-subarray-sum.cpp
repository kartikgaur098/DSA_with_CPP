class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> PS(n ,0) ;

        PS[0] = nums[0];
        for(int i = 1 ; i< n ; i++){
            PS[i] = PS[i-1] + nums[i] ;
        }

        unordered_map<int , int> mp ;

        for(int i = 0 ; i< n ; i++){
            int rem = PS[i] % k;

            if(rem == 0 && i>=1)
            return true ;

            if(mp.find(rem) != mp.end()){

                if(i - mp[rem] >=2){
                    return true ;
                }

            }else{
                mp[rem] = i ;
            }
        }

        return false ;
    }
};