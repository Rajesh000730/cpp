#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        int n = nums.size();
        int l = n-1;
        vector<int>ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n;i++){
            if(nums[i]+nums[l] == target){
                ans.push_back(nums[i]);
                ans.push_back(nums[l]);

            }
            else if(nums[i]+nums[l] > target){
                l--;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};