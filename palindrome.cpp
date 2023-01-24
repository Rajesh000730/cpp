#include<bits/stdc++.h>
using namespace std;

bool ispalindrome(string s){
  int n = s.size();
  int l = 0;
  int h = n-1;
  while(i < l){
     if(s[i] != s[h]) return false;     
  }
  return true;
}
