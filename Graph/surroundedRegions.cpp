class Solution {
public:
    vector<vector<int>>dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    bool isvalid(int i, int j, int m, int n){
        if(i >= 0 && j >=0 && i <m&& j < n){
            return true;
        }
        return false;
    }
    void dfs(int i, int j, vector<vector<char>>& board){
        board[i][j] = '#';
        for(int k = 0; k < 4;k++){
            int newrow = i + dir[k][0];
            int newcol = j + dir[k][1];
            if(isvalid(newrow, newcol, board.size(), board[0].size()) && board[newrow][newcol] == 'O'){
                dfs(newrow, newcol, board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                if((i*j==0 || i==m-1 || j==n-1)&&board[i][j]=='O'){
                    dfs(i, j, board);
                }
            }
        }
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
