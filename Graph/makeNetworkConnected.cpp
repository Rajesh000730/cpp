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
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjoint_set ds(n);
        for(auto edges : connections){
            ds.unio(edges[0]+1, edges[1]+1);
        }
        
        return ds.isconnectable();
    }
};
