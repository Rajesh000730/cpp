class TrieNode{
    public:
        TrieNode*children[2];
        TrieNode(){
            this->children[0] = NULL;
            this->children[1] = NULL;
        }
};
class Solution {
    TrieNode *root;
public:
    void insert(int x){
        TrieNode *curr =root;
        bitset<32>bs(x);
        for(int i = 31; i >= 0; i--){
            if(curr->children[bs[i]] == NULL){
                curr->children[bs[i]] = new TrieNode();
            }
            curr = curr->children[bs[i]];
        }
    }
    int findMaximumXOR(vector<int>& nums) {
        root = new TrieNode();
        for(int num: nums){
            insert(num);
        }
        int ans = 0;
        for(int n: nums){
            ans = max(ans, maxXOR(n));
        }

        return ans;

    }
    int maxXOR(int n){
         TrieNode *curr = root;
         bitset<32>bs(n);
         int ans = 0;
         for(int i = 31; i >= 0; i--){
             if(curr->children[!bs[i]] != NULL){
                 ans+=(1<<i);
                 curr = curr->children[!bs[i]];
             }
             else{
                 curr = curr->children[bs[i]];
             }
             
         }
         return ans;
    }
    
};
