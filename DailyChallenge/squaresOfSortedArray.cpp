class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        
        int left = 0;
        int right = n-1;

        for(int i = n-1; i >= 0;i--){
            int square;
            if(abs(nums[left]) < abs(nums[right])){
                square = nums[right];
                right--;
            }
            else{
                square = nums[left];
                left++;
            }
            ans[i] = square*square;
        }

        return ans;
    }
};
