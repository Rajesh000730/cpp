//https://leetcode.com/problems/find-peak-element/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, h = nums.size()-1, mid, mid1;
        while( l <= h){
            mid = (l+h)/2;
            mid1 = mid + 1;
            if(l == h){
                return l;
            }
            else if(nums[mid] > nums[mid+1]){
                h = mid;
            }
            else{
                l = mid1;
            }
        }
        return -1;
    }
};