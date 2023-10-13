//https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int h = nums.size()-2;
        int mid;
        while(l <= h){
            mid = (l+h)/2;
            if(nums[mid] == nums[mid ^ 1] ){
                l = mid + 1;
            }
            else{
                h = mid - 1;
            }
        }
        return nums[l];
    
    }
};