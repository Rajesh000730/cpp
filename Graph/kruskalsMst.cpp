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
    
};
