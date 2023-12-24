class Trie{
    public:
        Trie* children[27];
        int index = -1;
};

class WordFilter {
public:
    Trie*trie;
    WordFilter(vector<string>& words) {
        int n = words.size();
        trie = new Trie();
        for(int i = 0; i < n;i++){
            for(int j = 0; j < words[i].size();j++){
                string str = words[i].substr(j) + "{" + words[i];
                insertTrie(str, i);
            }
        }
    }
    void insertTrie(string word, int  pos){
        int index;
        Trie* curr = trie;
        for(char c : word){
            index = c - 'a';
            if(curr->children[index] == NULL){
                curr->children[index] = new Trie();
            }
            curr = curr->children[index];
            curr->index = pos;
        }
    }
    int searchTrie(string word){
         int index;
        Trie* curr = trie;
        for(char c : word){
            index = c - 'a';
            if(curr->children[index] == NULL){
                return -1;
            }
            curr = curr->children[index];
            
        }
       return curr->index;
    }
    
    int f(string pref, string suff) {
        return searchTrie(suff + "{" + pref);
    }
};
