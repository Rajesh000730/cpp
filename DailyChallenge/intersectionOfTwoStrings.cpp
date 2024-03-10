class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        vector<int>temp(1000, -1);
        int n = nums1.size();
        int m = nums2.size();;
        for(int i = 0; i < n;i++){
            temp[nums1[i]] = 1;
        }
        for(int i = 0; i < m;i++){
            if(temp[nums2[i]] == 1){
                ans.emplace_back(nums2[i]);
                temp[nums2[i]] = 0;
            }
        }
        return ans;
    }
};
