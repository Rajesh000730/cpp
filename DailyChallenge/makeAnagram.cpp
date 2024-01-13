class Solution {
public:
    int minSteps(string s, string t) {
        if(s.size()!=t.size()) return 0;
        map<char,int>m1;
        map<char,int>m2;
        int count = 0;
        for(char ch : s){
            m1[ch]+=1;
        }
        for(char ch : t){
            m2[ch]+=1;
        }
        for(char ch : s){
           if(!m2[ch]) ++count;
           if(m2[ch])--m2[ch];

        }
        return count;
        
    }
};
