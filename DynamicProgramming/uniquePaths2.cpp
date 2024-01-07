class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& M) {
        int m = M.size();
        int n = M[0].size();
        if (M[0][0] == 1)
            return 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));
        // column
        for (int i = 0; i < m; i++) {
            if (M[i][0] == 0) {
                dp[i][0] = 1;
            } else {
                break;
            }
        }
        for (int j = 0; j < n; j++) {

            if (M[0][j] == 0) {
                dp[0][j] = 1;
            } else {
                break;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (M[i][j] == 0) {
                    if (dp[i - 1][j] == 0 || dp[i][j - 1] == 0) {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    } else {
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                    }
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
