class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto flight : flights){
            int node = flight[0];
            int edge = flight[1];
            int cost = flight[2];
            adj[node].push_back({edge, cost});
        }
        vector<int>dist(n, INT_MAX);
        dist[src] = 0;
        queue<pair<int,pair<int,int>>>pq;
        pq.push({0, {src,0}});
        while(!pq.empty()){
            int steps = pq.front().first;
            int node = pq.front().second.first;
            int cost = pq.front().second.second;
            pq.pop();
            if(steps > k) continue;
            for(auto x : adj[node]){
                int wt = x.second;
                int edge = x.first;
                if((dist[edge] > cost + wt) && steps<=k){
                    dist[edge] = cost + wt;
                    pq.push({steps+1, {edge, dist[edge]}});
                }
            }
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
        
    }
};
