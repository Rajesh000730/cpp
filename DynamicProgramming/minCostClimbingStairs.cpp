class Solution {
public:
    int util(vector<int>cost, int n){
        if(n==0 || n==1){
            return cost[n];
        }
        int pickfirst = cost[n]+util(cost, n-1);
        int picksecond = cost[n]+util(cost,n-2);
        return min({pickfirst, picksecond}); 
    }
    int minCostClimbingStairs(vector<int>& cost) {
        cost.emplace_back(0);
        int n = cost.size();
        vector<int>dp(n, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < n;i++){
            int pickfirst = cost[i]+dp[i-1];
            int picksecond = cost[i]+dp[i-2];
            dp[i] = min({pickfirst, picksecond});
        }
        return dp[n-1];
    }
};

