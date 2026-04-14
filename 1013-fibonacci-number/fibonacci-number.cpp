class Solution {
public:
    int fibRec(int n) {
       if(n == 0) return 0 ;
       if(n == 1) return 1 ;

       int ans = fibRec(n-1) + fibRec(n-2);
       return ans ;
    }

      int fibusingMemoization(int n , vector<int> &dp) {
        // Pure recursive apporach ;

        // Memoization steps -
    // step 1: isme sbse pehle check krte h 1D , 2D , 3D konsi DP lgegi ye krenge hm jitne variables change rhe h uske base pr 
    // step 2: iske bad vector ko pass krenge funtion m or store krayenge vector m he 
    // step 3: base condition k bad check krenge kya ans already pda h array k andr agr hn to return krdenge

       if(n == 0) return 0 ;
       if(n == 1) return 1 ;
        if(dp[n] != -1){
            return dp[n];
        }
       dp[n] = fibusingMemoization(n-1 , dp) + fibusingMemoization(n-2, dp);
       return dp[n] ;
    }


    int fibusingTabulation(int n){
        // Pure iterative apporach ;
        // create a dp array 
        vector<int> dp(n+1 , -1);

        // check base in recusrsion and update array
        dp[0] = 0 ;
        if(n == 0 ) return 0 ;
        dp[1] = 1 ;

        // check parameter reverse it and run a loop
         for(int i = 2 ; i <= n ; i++){
            dp[i] = dp[i-1] + dp[i-2];
         }

        return dp[n];
    }

    int fibusingTabulationSpaceOptimized(int n){
        int prev = 0 ;
        int curr = 1 ;
         if(n == 0 ) return 0 ;
        for(int i = 2 ; i<= n ; i++){
            int ans = prev + curr ;
            prev = curr ;
            curr = ans ;
        }

        return curr ;
    }
    int fib(int n) {
        //  memoization 
    //    vector<int> dp(n+1, -1);
    //    int ans = fibusingMemoization(n , dp);
    //    return ans ;

        // Tabulation
        // return fibusingTabulation(n);

        // Spaceoptimized
        return fibusingTabulationSpaceOptimized(n);
    }
};