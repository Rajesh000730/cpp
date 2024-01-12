class Solution {
public:
    bool halvesAreAlike(string s) {
        vector<char>v = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int count = 0;
        int n = s.size();
        for(int i = 0; i < n/2; i++){
            if(find(v.begin(), v.end(), s[i])!=v.end()){
                ++count;
            }
        }
        for(int i = n/2; i < n; i++){
            if(find(v.begin(), v.end(), s[i])!=v.end()){
                --count;
            }
        }
        if(count!=0)return false;
        return true;
    }
};
