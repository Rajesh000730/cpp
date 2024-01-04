class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 1;
        int ans = 0;
        for (int i = 1; i < n+1; i++) {
            if (i < n && nums[i] == nums[i - 1]) {
                ++count;
            } else {
                if (count == 1)
                    return -1;
                else if (count % 3 == 0) {
                    ans += count / 3;
                } else {
                    ans += (count / 3) + 1;
                    count = 1;
                }
            }
        }
        return ans;
    }
};
