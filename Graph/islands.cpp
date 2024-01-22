class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || vis[i][j] || grid[i][j]=='0') return;
        vis[i][j] = 1;
        dfs(grid, vis, i-1, j);
        dfs(grid, vis, i+1, j);
        dfs(grid, vis, i, j-1);
        dfs(grid, vis, i, j+1);

    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<int>>vis(m, vector<int>(n, 0));
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                if(grid[i][j] != '0' && !vis[i][j]){ 
                ++count;
                dfs(grid, vis, i, j);
                }
    
            }
        }
        return count;


    }
};
