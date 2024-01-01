class Solution {
public:
    int util(vector<int>&nums, int ind, int n, vector<int>&dp){
        dp[ind] = nums[ind];
        for(int i = ind+1; i <= n;i++){
            int pick = nums[i];
            if(i >= ind + 2){
                pick += dp[i-2];
            }
            int notpick = dp[i-1];
            dp[i] = max(pick, notpick);
        }
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[1], nums[0]);
        vector<int>dp(n, -1);
        int notend = util(nums, 0, n-2, dp);
        dp = vector(n, -1);
        int notbeg = util(nums, 1, n-1, dp);
        return max(notend, notbeg);

    }
};
