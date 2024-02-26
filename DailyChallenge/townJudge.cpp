class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size() == 0){
            if(n==1){
                return 1;
            }
            else{
                return -1;
            }
        }
        map<int,int>mp1;
        map<int,int>mp2;
        for(vector<int>tr : trust){
            mp1[tr[0]]+=1;
            mp2[tr[1]]+=1;
        }
        for(auto it : mp2){
            if(it.second == n-1){
                if(mp1[it.first] == 0){
                    return it.first;
                }
            }
        }
        return -1;
    }
};
