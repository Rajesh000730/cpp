class Solution {
public:
    vector<vector<int>>dir = {{-1,0},{0,-1},{1,0},{0,1}};
    bool isvalid(int i, int j, int m, int n){
        if(i >= 0 && j >=0 && i < m && j < n){
            return true;
        }
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>vis(m, vector<bool>(n, false));
        vector<vector<int>>dis(m, vector<int>(n, 0));
        queue<pair<int,int>>q;
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    vis[i][j]=true;
                }
            }
            }
        while(!q.empty()){
            pair<int,int>curr = q.front();
            q.pop();
            for(int k = 0; k < 4;k++){
                int ni = curr.first + dir[k][0];
                int nj = curr.second + dir[k][1];
                if(isvalid(ni, nj, m, n) && vis[ni][nj] == false && grid[ni][nj] == 1){
                    grid[ni][nj] = 2;
                    vis[ni][nj] = true;
                    dis[ni][nj] = dis[curr.first][curr.second]+1;
                    q.push({ni, nj});
                }

            }
        }
        int ans = -1;
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
                ans = max(ans, dis[i][j]);
            }
        }
        return ans;
    }
    
};
