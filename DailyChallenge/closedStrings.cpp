class Solution {
public:
    bool closeStrings(string word1, string word2) {
       int m = word1.size();
       int n = word2.size();
       if(m != n) return false;
        bool flag = false;
       vector<int>v1(26, 0);
       vector<int>v2(26, 0);
       for(int i = 0; i < n;i++){
           v1[word1[i] - 'a'] +=1;
           v2[word2[i] - 'a'] +=1;
       } 

       for(int i = 0; i < n;i++){
           if(v2[word2[i] - 'a'] == 0 || v1[word2[i] - 'a'] == 0 || v1[word1[i] - 'a'] == 0 || v2[word1[i] - 'a'] == 0){
               return false;
           }
       }
       
       sort(v1.begin(), v1.end());
       sort(v2.begin(), v2.end());

       for (int i = 0; i < 26; i++) {
            if (v1[i] != v2[i]) {
                return false;
            }
        } 
       return true;
       
    }
};
