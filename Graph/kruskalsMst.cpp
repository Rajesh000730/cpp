//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

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
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {   vector<pair<int,pair<int,int>>>edges;
        for(int i = 0; i < V;i++){
            for(auto x : adj[i]){
                int node = i;
                int edge = x[0];
                int wt = x[1];
                edges.push_back({wt, {node, edge}});
            }
            
        }
        sort(edges.begin(),edges.end());
        Disjoint_set ds(V);
        // int n = edges.size();
        int mst = 0;
        for(auto x : edges){
            int wt = x.first;
            int u = x.second.first;
            int v = x.second.second;
            if(ds.findParent(u) != ds.findParent(v)){
                mst+=wt;
                ds.unio(u, v);
            }
        }
        return mst;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
