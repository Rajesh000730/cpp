class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int miss, repeat;
        vector<int>v(n+1,0);
        for(int i = 0; i < n;i++){
            v[nums[i]]+=1;
        }
        for(int i = 1; i <= n;i++){
            if(v[i] == 0){
                miss = i;
            }
            if(v[i] > 1){
                repeat = i;
            }
        }

        
        return {repeat, miss};
    }
};
