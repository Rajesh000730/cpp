class Solution {
public:
    int kthFactor(int n, int k) {
       priority_queue<int, vector<int>, greater<int>>pq;
       for(int i = 1; i <= n; i++){
           if(n%i==0){
               pq.push(i);
           }
       } 
       while(!pq.empty() && --k){
           pq.pop();
       }
       if(pq.empty())return -1;
       return pq.top();
    }
};
