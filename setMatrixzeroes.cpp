#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      vector<pair<int,int>>p;
      vector<int>row;
      vector<int>col;
      int m = matrix.size();
      int n = matrix[0].size();
      for(int i = 0; i < m; i++){
        for(int j = 0; j < n ;j++){
          if(matrix[i][j] == 0){
            row.emplace_back(i);
            col.emplace_back(j);
          }
        }
      }
      for(int i =0; i < m; i++){
        for(int j = 0; j < n; j++){
          if(row[i] == 1 || col[j] == 1){
            matrix[i][j] = 0;
        }
      }
    }
  }
};
