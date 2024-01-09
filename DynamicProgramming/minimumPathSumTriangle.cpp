class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int ans = 1e5+1;
        if(m==1) return triangle[0][0];
        vector<vector<int>>dp(m+1, vector<int>(m+2, 1e5+1));
        for(int i = 1; i <= m;i++){
            for(int j = 1; j <=i;j++){
                if( i==1 && j == 1){
                    dp[i][j] = triangle[i-1][j-1];
                }
                else{
                    dp[i][j] = min({dp[i-1][j], dp[i-1][j-1]}) + triangle[i-1][j-1];
                    if(i == m){
                        ans = min(ans, dp[i][j]);
                    }
                }
            }
        }
        return ans;
    }
};
