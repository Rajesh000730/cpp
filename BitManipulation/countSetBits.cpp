#include<bits/stdc++.h>

using namespace std;

int countSetBits(int n){
    
    int count = 0;
    while(n){
        ++count;
        n = n & n - 1;

    }
    return count;
}

int main(){
    int ans;
    int qn = 9;
    ans = countSetBits(qn);
    cout<<ans;

    return 0;
}
