class Solution {
public:
     bool dfs(int node,  vector<int>&check, vector<int>&vis, vector<vector<int>>& graph, vector<int>&pathvis){
        vis[node] = 1;
        check[node] = 1;
        pathvis[node] = 1;
        for(auto adj : graph[node]){
            if(vis[adj]==0){
                if(dfs(adj, check, vis, graph, pathvis) == true){
                    check[node] = 0;
                    return true;
                }
            }
            else{
                if(pathvis[adj]){
                    check[node] = 0;
                    return true;
                }
            }
        }
        pathvis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        int m = graph.size();
        vector<int>vis(m, 0);
        vector<int>check(m, 0);
        vector<int>pathvis(m, 0);
        for(int i = 0; i < m;i++){
            if(vis[i]==0){
                dfs(i, check, vis, graph, pathvis);
            }
        }
        for(int i = 0; i < m;i++){
            if(pathvis[i] == 0){
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};
