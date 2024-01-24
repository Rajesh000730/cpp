class Solution {
public:
    bool isvalid(int i, int j, int m, int n){
        if(i>=0 && j >=0 && i < m && j<n){
            return true;
        }
        return false;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<bool>>seen(m, vector<bool>(n, false));
        vector<vector<int>>dist(m, vector<int>(n, 0));
        vector<vector<int>>dir = {{-1,0}, {1,0}, {0,1}, {0,-1}};
        queue<vector<int>>q;
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                if(mat[i][j] == 0){
                    q.push({i, j, 0});
                    seen[i][j] = true;
                }
            }
        }
        while(!q.empty()){
            vector<int>source = q.front();
            q.pop();
            for(int k = 0; k < 4;k++){
                int newrow = source[0] + dir[k][0];
                int newcol = source[1] + dir[k][1];
                int level = source[2];
                if(isvalid(newrow, newcol,m ,n) && !seen[newrow][newcol]){
                    seen[newrow][newcol] = true;
                    q.push({newrow, newcol, level+1});
                    dist[newrow][newcol] = level+1;
                }
            }
        }
        return dist;

    }
};
