class Solution {
public:
    int climbStairs(int n) {
        // At any point, 1 or 2 steps
        // Make array, how many ways to get to n
        // Base case: n-1: 1 way; n-2: 2 ways
        vector<int> dp(n+1, 0);
        
        dp[n] = 1;
        dp[n-1] = 2;
        for (int i = n-2; i >= 1; i--) {
            dp[i] = dp[i+1] + dp[i+2];
        }

        return dp[1];
    }
};
