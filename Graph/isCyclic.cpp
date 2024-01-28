//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>ind(V, 0);
        vector<int>v;
        queue<int>q;
        for(int i = 0; i < V;i++){
            for(auto x : adj[i]){
                ind[x]++;
            }
        }
        for(int j  = 0; j < V;j++){
            if(ind[j] == 0){
                q.push(j);
            }
        }
        while(!q.empty()){
            int top = q.front();
            q.pop();
            v.push_back(top);
            for(auto x : adj[top]){
                ind[x]--;
                if(ind[x] == 0){
                    q.push(x);
                }
            }
        }
        if(v.size()!=V){
            return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
