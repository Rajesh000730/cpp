#include<bits/stdc++.h>

using namespace std;

int nonrepeatingnumber(vector<int>v){
    int xor_op = v[0];
    
    for(int i = 1; i < v.size();i++) xor_op ^= v[i];
    
    return xor_op;

}

int main(){
    int ans;
    vector<int>qn = {1,1,2,2,3,4,4};
    ans = nonrepeatingnumber(qn);
    cout<<ans;
} 