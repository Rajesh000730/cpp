class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char,int>mp;
        for(char x : s){
            mp[x]+=1;
        }
        vector<char>st ;
        st.push_back(s[0]);
        int n = s.size();
        map<char,int>seen;
        for(int i = 1; i < n;i++){
            if(find(st.begin(), st.end(), s[i])== st.end() ){
                while(!st.empty() && s[i] <= st.back() && mp[st.back()] > 1){
                mp[st.back()]-=1;
                // seen[s[i]]=1;
                st.pop_back();
            }
                st.push_back(s[i]);
            }
            else{
                mp[s[i]]-=1;
            }
        }
        string ans = "";
        for(auto c: st){
            ans+=c;
        }
        // reverse(ans.begin(), ans.end());
        return ans;
    }
};
