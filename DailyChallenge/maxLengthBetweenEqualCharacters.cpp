class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int>ind(26, 0);
        int n = s.size();
        int ans = -1;
        for(int i = 0; i < n;i++){
            if(ind[s[i] - 'a'] == 0){ // if the character is appearing for the first time initialize ind[ch - 'a'] with its index.
                ind[s[i] - 'a'] = i + 1;// one based indexing
            }
            else{
                ans = max(ans, i  - ind[s[i] - 'a']); // else find the maximum difference between the two character.
            }
        }
        return ans;
    }
};
