class Solution {
public:
    int util(vector<int>&nums, int n, vector<int>&dp){
        if( n == 0){
            return nums[n];
        }
        if(n < 0) return 0;
        if(dp[n]!=-1) return dp[n];
        int pick = nums[n] + util(nums, n-2, dp);
        int notpick = 0+util(nums, n - 1, dp);
        return dp[n] = max(pick, notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 2) return max(nums[1], nums[0]);
        vector<int>dp(n, -1);
        return util(nums, n - 1, dp);
    }
};
