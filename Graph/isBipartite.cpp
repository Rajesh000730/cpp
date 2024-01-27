class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int m = graph.size();
        vector<int> colors(m, -1);

        for (int i = 0; i < m; i++) {
            if (colors[i] == -1) {
                queue<int> q;
                q.push(i);
                colors[i] = 0;
                while (!q.empty()) {
                    int x = q.front();
                    q.pop();
                    for (int adj : graph[x]) {
                        if (colors[adj] == -1) {
                            colors[adj] = !colors[x];
                            q.push(adj);
                        } else if (colors[adj] == colors[x]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
