class Solution {
public:
    int solveRec(vector<int> &nums , int i ){
        if(i >= nums.size() ){
            return 0 ;
        }
        int include = nums[i] + solveRec(nums , i+2);
        int exclude = 0 + solveRec(nums , i+1);
        int ans = max(include , exclude);
        return ans ;
    }

    int solveMemoization(vector<int> &nums , int i,vector<int> &dp){
        // Pure recursion se hoga bs dp array ka use krna h 
        if(i >= nums.size() ){
            return 0 ;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int include = nums[i] + solveMemoization(nums , i+2 , dp);
        int exclude = 0 + solveMemoization(nums , i+1 , dp);
        dp[i] = max(include , exclude);
        return dp[i] ;
    }

      int solveTabulation(vector<int> &nums){
 int n = nums.size(); 
    vector<int> dp(n+2, 0); 

    for(int i = n-1; i >= 0; i--){
        int include = nums[i] + dp[i+2];
        int exclude = dp[i+1];
        dp[i] = max(include , exclude);
    }

    return dp[0];
    }

    int rob(vector<int>& nums) {
        int finalans = solveTabulation(nums);
        return finalans ;
    }
};