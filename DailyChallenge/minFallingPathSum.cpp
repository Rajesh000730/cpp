class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 1) return matrix[0][0];
        vector<vector<int>> dp(n, vector<int>(n + 2, INT_MAX));
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <n+1; j++) {
                if (i == 0) {
                    dp[i][j] = matrix[i][j-1];
                }
                else{
                    dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]}) + matrix[i][j-1];
                    if(i == n-1){
                        ans = min(ans, dp[i][j]);
                    }
                }
                
            }
        }
        return ans;
    }
};
