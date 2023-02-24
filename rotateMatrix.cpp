#include<bits/stdc++.h>

using namespace std;

void rotateMatrix(vector<vector<int>> &matrix){
   for(int i = 0; i < n; i++){
      for(int j = i + 1; j < n; j++ ){
          int temp = matrix[i][j];
          matrix[i][j] = matrix[j][i];
          matrix[j][i] = temp; 
      }
   }    

   int ind = n - 1;
   for(int i = 0; i < n; i++){
      for(int j = 0; j < n/2; j++){
          
      }
   }
}
