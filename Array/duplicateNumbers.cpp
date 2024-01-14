class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        do{
            i = nums[i];
            j = nums[nums[j]];
            
        }while(i!=j);
        i = 0;
        while(i!=j){
         i = nums[i];
         j = nums[j];
        }
        return i;
    }
};
