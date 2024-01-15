class Solution {
public:
    int util(int ind, int tar, vector<int>&coins, vector<vector<int>>&dp){
        if(ind == 0){
            return tar%coins[ind] == 0;
        }
        if(dp[ind][tar]!=-1){
            return dp[ind][tar];
        }
        int not_take = util(ind - 1, tar, coins, dp);
        int take = 0;
        if(coins[ind] <= tar) take = util(ind, tar-coins[ind], coins, dp);
        return dp[ind][tar] = take+not_take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1,-1));
        for(int t = 0; t <= amount;t++){
            dp[0][t] = t%coins[0] == 0;
        }
        for(int ind = 1; ind < n;ind++){
            for(int tar = 0; tar <= amount;tar++){
                int not_take = dp[ind-1][tar];
                int take = 0;
                if(coins[ind] <= tar) take = dp[ind][tar-coins[ind]];
                dp[ind][tar] = take+not_take;
            }
        }
        return dp[n-1][amount];
    }
};
