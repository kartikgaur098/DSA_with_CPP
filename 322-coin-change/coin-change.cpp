class Solution {
public:
    int solve(vector<int>& coins, int amount){
        if( amount == 0 ){
            return 0 ;
        }
         int mincoinans = INT_MAX;
        for(int i=0 ; i< coins.size() ; i++){
            int coin = coins[i];

            if(coin <= amount){
                int recAns = solve(coins , amount - coin);

                if(recAns != INT_MAX){
                    int coinsused = 1+ recAns ;
                    mincoinans = min(coinsused , mincoinans);
                }
            }
        }
        return mincoinans ;
    }

      int solveMem(vector<int>& coins, int amount , vector<int> &dp){
        if( amount == 0 ){
            return 0 ;
        }

        if(dp[amount]!= -1){
            return dp[amount];
        }
         int mincoinans = INT_MAX;
        for(int i=0 ; i< coins.size() ; i++){
            int coin = coins[i];

            if(coin <= amount){
                int recAns = solveMem(coins , amount - coin , dp);

                if(recAns != INT_MAX){
                    int coinsused = 1+ recAns ;
                    mincoinans = min(coinsused , mincoinans);
                }
            }
        }
        dp[amount] = mincoinans ;
        return dp[amount] ;
    }




    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1 , -1);
        int ans = solveMem(coins , amount  , dp);
        if(ans == INT_MAX){
            return -1 ;
        }

        return ans ;
    }
};