class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>temp;
        int maxrow = 1;
        for(int num : nums){
            ++temp[num];
            maxrow = max(maxrow, temp[num]);
        }
        vector<vector<int>>ans(maxrow);

        for(auto x: temp){
            while(x.second){
                ans[x.second - 1].emplace_back(x.first);
                x.second--;
            }
        }
        return ans;
        
    }
};
