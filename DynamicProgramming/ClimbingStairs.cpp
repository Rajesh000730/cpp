class Solution {
public:
    int climbStairs(int n) {

        vector<int>dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <=n;i++){
            int first = dp[i-1];
            int second = dp[i-2];
            dp[i] = first + second;
        }
        return dp[n];

    }
};
