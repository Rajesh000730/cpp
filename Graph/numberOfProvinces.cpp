
class Disjoint_set{
    vector<int>parent, rank;
    public:
        Disjoint_set(int n){
            parent = vector<int>(n+1);
            rank = vector<int>(n+1, 0);
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
            if(up_u == up_v) return;
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
    
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        Disjoint_set ds(n);
        vector<vector<bool>>vis(n, vector<bool>(n, false));
        for(int i = 0; i < n;i++){
            for(int j = 0; j < n;j++){
                if(vis[i][j] == false && isConnected[i][j] == 1){
                    ds.unio(i+1, j+1);
                    vis[i][j] = true;
                    vis[j][i] = true;
                }
            }
        }
        return ds.bosses();
    }
};
