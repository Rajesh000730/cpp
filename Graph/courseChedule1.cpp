class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<int>ind(numCourses, 0);
        vector<vector<int>>adj(numCourses);
        for(int i = 0; i < n; i++){
            ind[prerequisites[i][1]]++;
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        queue<int>q;
        vector<int>v;
        for(int i = 0; i < numCourses;i++){
            if(ind[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int top = q.front();
            q.pop();
            v.push_back(top);
            for(auto x : adj[top]){
                ind[x]--;
                if(ind[x] == 0){
                    q.push(x);
                }
            }
        }
        if(v.size()!=numCourses){
            return false;
        }
        return true;
    }
};
