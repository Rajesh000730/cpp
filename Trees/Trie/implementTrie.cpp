class TrieNode {
    vector<TrieNode*>chs(26, NULL);
public:
    
    bool endOfword;
    TrieNode() {
        endOfWord = false;
    }
};
class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string s) {
        int n = s.size();  
        for(int i = 0; i < n; i++){
            Trie *curr = root;
            int k = s[i] - 'a';              
            if(curr->chs[k] == NULL){
                curr->chs[k] = new TrieNode(); 
            }
            curr = curr->chs[k]; 
    }
        return current->endOfword;
    }       
    }
    bool search(string key) {
        int n = s.size();  
        for(int i = 0; i < n; i++){
            Trie *curr = root;
            int k = s[i] - 'a';              
            if(curr->chs[k] == NULL){
                return false;
            }
            curr = curr->chs[k]; 
    }
        return current->endOfword;
}
    bool startsWith(string prefix) {
       
    }
};
