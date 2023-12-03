#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
using namespace std;
class Solution{
  public:
    int maxSubarraySum(vector<int>&nums){
      int currsum = 0;
      int maxSofar = INT_MIN;
      for(int x : nums){
        currsum+=x;
        maxSofar = max(maxSofar, currsum);
        if(currsum < 0) currsum = 0;
      }
      return maxSofar;
   }
};
