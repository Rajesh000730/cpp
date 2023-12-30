class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size(), n = s.size();
        int l = 0, k = 0, ans = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(k < m && l < n){
            if(g[k] <= s[l]){
                ++ans;
                ++k;
                ++l;
            }
            else{
                ++l;
            }
        }
        return ans;
    }
};
