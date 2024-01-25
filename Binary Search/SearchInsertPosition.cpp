class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int n = nums.size()-1;
        int mid;
        if(target <= nums[0]){
            return 0;
        }
        while(l <= n){
            mid = (l+n)/2;
            if(nums[mid] >= target){
                n = mid-1;
            }
            else if(nums[mid] <= target){
                l = mid+1;
            }
        }
        
        return n+1;
    }
};
