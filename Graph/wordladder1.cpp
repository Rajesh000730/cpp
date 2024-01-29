class Solution {
public:
    int ladderLength(string beginword, string endword, vector<string>& wordlist) {
        unordered_set<string>st(wordlist.begin(), wordlist.end());
        queue<pair<string,int>>q;
        q.push({beginword, 1});
        st.erase(beginword);
        while(!q.empty()){
            string word = q.front().first;
            int level = q.front().second;
            q.pop();
            if(word == endword){
                return level;
            }
            for(int i = 0; i < word.size();i++){
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(st.find(word)!=st.end()){
                        q.push({word, level+1});
                        st.erase(word);
                    }
                }
                word[i] = original;
            }

        }
        return 0;
    }
};
