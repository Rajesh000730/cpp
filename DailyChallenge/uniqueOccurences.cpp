class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int x : arr){
            mp[x]+=1;
        }
        priority_queue<int>pq;
        for(auto x : mp){
            pq.push(x.second);
        }
        int top = pq.top();
        pq.pop();
        while(!pq.empty()){
            int t = pq.top();
            if(top==t){
                return false;
            }
            top = t;
            pq.pop();
        }
        return true;

    }
};
