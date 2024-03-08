class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxFrequency = 0;
        int ans = 0;
        map<int,int>mp;
        for(int i : nums){
            mp[i]+=1;
            maxFrequency = max(maxFrequency, mp[i]);
        }
        for(auto x : mp){
            if(x.second == maxFrequency){
                ans+=maxFrequency;
            }
        }
        return ans;
    }
};
