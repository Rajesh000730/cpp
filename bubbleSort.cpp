#include<bits/stdc++.h>

using namespace std;

void bubbleSort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1;j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }    
        }
    }
}


// printing the array after sorting

for(int i = 0; i < n; i++){
    cout << arr[i] << " ";
}


//Time Complexity: O(n^2), (beacause of nested for loop)
//Space Complexity: O(1)
