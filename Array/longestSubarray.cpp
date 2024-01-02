class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int>temp;
        int n = nums.size();
        int maxsofar = 0;
        int maxsum = INT_MIN;
        for(int i = 0; i < n;i++){
            if(nums[i] == 0){
                if(maxsofar){
                    temp.emplace_back(maxsofar);
                    maxsofar = 0;
                }
                temp.emplace_back(0);
            }
            else{
                ++maxsofar;
            }
        }
        if(maxsofar)temp.emplace_back(maxsofar);
        if(maxsofar == n){
            return n-1;
        }
        n = temp.size();
        for(int i = 0; i < n;i++){
                if(i+2 < n){
                    maxsum = max(maxsum, temp[i]+temp[i+2]);
                }
                else{
                    maxsum = max(maxsum , temp[i]);
                }
        }
        return maxsum==INT_MIN?0:maxsum;
    }
};
