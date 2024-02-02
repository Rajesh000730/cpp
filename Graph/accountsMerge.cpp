#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Disjoint_set{
    vector<int>parent, rank;
    int extra;
    public:
        Disjoint_set(int n){
            parent = vector<int>(n+1);
            rank = vector<int>(n+1, 0);
            extra = 0;
            for(int i = 1; i <= n;i++){
                parent[i] = i;
            }
        }
        int findParent(int u){
            if(parent[u] == u){
                return u;
            }
            return parent[u] = findParent(parent[u]);
        }
        void unio(int u, int v){
            int up_u = findParent(u);
            int up_v = findParent(v);
            if(up_u == up_v) {
                extra+=1;
                return;
            };
            if(rank[up_u] < rank[up_v]){
                parent[up_u] = up_v;
            }
            else if(rank[up_u] > rank[up_v]){
                parent[up_v] = up_u;
            }
            else {
                parent[up_v] = up_u;
                rank[up_u]+=1;
            }

        }
        bool isbelong(int u, int v){
            if(parent[u] == parent[v]){
                return true;
            }
            return false;
        }
        int bosses(){
            int n = parent.size()-1;
            int count = 0;
            for(int i = 1; i <= n;i++){
                if(parent[i] == i){
                    ++count;
                }
            }
            return count;
        }
        int isconnectable(){
            int x = bosses() - 1;
            if(extra >= x){
                return x;
            }
            return -1;
        }

};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int>mp;
        int n = accounts.size();
        Disjoint_set ds(n);
        for(int i = 0; i < n;i++){
            for(int j = 1; j < accounts[i].size();j++){
                if(mp.find(accounts[i][j]) == mp.end()){
                    mp[accounts[i][j]] = i+1;
                }
                else{
                    ds.unio(i+1, mp[accounts[i][j]]);
                }
            }
        } 
        vector<string>mergeMail[n];    
        vector<vector<string>>ans;
        for(auto x : mp){
            string str = x.first;
            int node = ds.findParent(x.second);
            mergeMail[node-1].push_back(str);
            
        } 
        for(int i = 0; i < n;i++){
             if(mergeMail[i].size() == 0) continue;
             sort(mergeMail[i].begin(), mergeMail[i].end());
             vector<string>temp;
             temp.push_back(accounts[i][0]);
             for(auto x : mergeMail[i]){
                 temp.push_back(x);
             }
             ans.push_back(temp);
        }
        return ans;
    }
};
