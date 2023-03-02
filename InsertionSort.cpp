// hint: insert elements from the unsorted portion to the sorted portion

#include<bits/stdc++.h>

using namespace std;

void InsertionSort(vector<int> &arr){
  int n = arr.size();
  int current;
  for(int i = 1; i < n; i++){
      // storing arr[i] to current element
      current = arr[i];
      int j = i-1;
      // comparing if arr[j] is greater than current until j is greater than 0
      while(j > 0 && arr[j] > current){
         // copy arr[j + 1] to arr[j]
         arr[j] = arr[j + 1];
         j--;
      }
      // copy current to arr[j + 1]
      arr[j + 1] = current;
  }

// #printing the array
for(auto x : arr){
    cout << x << " ";
}



}


