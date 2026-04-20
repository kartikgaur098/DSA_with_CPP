class Solution {
public:
    // int climbStairs(int n) {
    //     if (n <= 2) return n;
    // return climbStairs(n - 1) + climbStairs(n - 2);
    // }

    // int climbStairs(int n) {
    //     if (n <= 2)
    //         return n;

    //     vector<int> dp(n + 1);
    //     dp[1] = 1;
    //     dp[2] = 2;

    //     for (int i = 3; i <= n; i++) {
    //         dp[i] = dp[i - 1] + dp[i - 2];
    //     }

    //     return dp[n];
    // }

    int climbStairs(int n) {
    if (n <= 2) return n;

    int prev2 = 1; // dp[i-2]
    int prev1 = 2; // dp[i-1]

    for (int i = 3; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}
};