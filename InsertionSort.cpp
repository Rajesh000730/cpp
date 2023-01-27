#hint: insert elements from the unsorted portion to the sorted portion

#include<bits/stdc++.h>

using namespace std;

void InsertionSort(vector<int> &arr){
  int n = arr.size();
  int current;
  for(int i = 1; i < n; i++){
      current = arr[i];
      j = i-1;
      while(j > 0 && arr[j] > current){
         arr[j] = arr[j + 1];
         j--;
      }
      arr[j + 1] = current;
  }

#printing the array
for(auto x : arr){
    cout << x << " ";
}



}


