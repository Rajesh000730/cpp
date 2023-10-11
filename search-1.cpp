// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& arr, int target) {

        int n = arr.size();
        int l = 0;
        int h = n-1;
        int mid;
        while( l <= h){
            mid = (l+h)/2;
            if(arr[mid] == target){
                return mid;
            }
            if(arr[l] <= arr[mid]){
                if(arr[l] <= target && target <= arr[mid]){
                    h = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            else{
                if(arr[mid] <= target && target <=arr[h]){
                    l = mid + 1;
                }
                else{
                    h = mid - 1;
                }
            }
        }

        return -1;
    }
};