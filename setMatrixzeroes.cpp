#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      vector<pair<int,int>>p;
      vector<int>row;
      vector<int>col;
      for(int i = 0; i < matrix.size(); i++){
          for(int j = 0; j < matrix[0].size();j++){
              if(matrix[i][j] == 0){
                 p.push_back({i,j});
              }
          }
      }
      for(auto x : p){
          if(find(row.begin(),row.end(),x.first) == row.end())
          {
            for(int j = 0; j < matrix[0].size();j++){
                matrix[x.first][j] = 0;
            }
            row.push_back(x.first);
          }
          if(find(col.begin(), col.end(), x.second)==col.end())
          {
            for(int j = 0; j < matrix.size();j++){
                matrix[j][x.second] = 0;
            }
            col.push_back(x.second);
          }
      }
    }
};
