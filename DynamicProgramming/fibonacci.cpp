class Solution {
public:
    int fib(int n) {
        if(n==0||n==1)return n;
        vector<int>dp(n+1,0);
        dp[0]=0;
        dp[1]=1;
        for(int i = 2; i <= n;i++){
            int first = dp[i-1];
            int second = dp[i-2];
            dp[i] = first+second;
        }
        return dp[n];
    }
};
