//https://leetcode.com/problems/first-missing-positive/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int mini = INT_MAX;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(auto x : nums){
            if(x > 0){
                mini = min(mini, x);
            }
        }
         if(mini != 1){
                return 1;
            }
        for(int i = 0; i < n-1; i++){
            if(nums[i]+1 != nums[i+1] && nums[i]+1 > 0 && nums[i]!=nums[i+1]){
                return nums[i]+1;
            }
        }
            return nums[n-1] + 1;
        
        
    }
};