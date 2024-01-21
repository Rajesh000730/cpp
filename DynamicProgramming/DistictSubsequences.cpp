class Solution {
public:
    int util(string s, string t, int i, int j, vector<vector<int>>&dp){
        if(j < 0) return 1;
        if(i < 0) return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i] == t[j]){
            return dp[i][j] = util(s, t, i-1, j-1, dp)+util(s, t, i-1, j, dp);
        }
        else{
            return dp[i][j] = util(s, t, i-1, j, dp);
        }
    }
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        int mod = 1e9+7;
        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
        for(int i = 0; i <=m ;i++){
            dp[i][0] = 1;
        }
        for(int i = 1; i <= m ;i++){
            for(int j = 1; j <= n;j++){
                if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                dp[i][j] = (dp[i][j])%mod;
                }
                else{
                dp[i][j] = dp[i-1][j];
                dp[i][j] = dp[i][j]%mod;
        }
            }
        }
        return dp[m][n];
    }
};
