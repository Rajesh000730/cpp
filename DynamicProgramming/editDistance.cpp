class Solution {
public:
    int util(string s, string t, int i, int j,vector<vector<int>>dp){
        if(i < 0) return j+1;
        if(j < 0) return i+1;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==t[j]){
            return dp[i][j] = util(s, t, i-1, j-1, dp);
        }
            return dp[i][j] = min({1+util(s,t,i-1,j,dp), 1+util(s,t,i-1,j-1,dp), 1+util(s,t,i,j-1,dp)});
        }

    int minDistance(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
        for(int i = 0; i <= n;i++){
            dp[0][i] = i; 
        }
        for(int i = 0; i <= m;i++){
            dp[i][0] = i; 
        }
        for(int i = 1; i <= m;i++){
            for(int j = 1; j <= n; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min({1+dp[i-1][j], 1+dp[i-1][j-1], 1+dp[i][j-1]});
                }
            }
        }
        return dp[m][n];
    }
};
