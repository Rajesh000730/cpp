class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int>winners;
        vector<int>losers;
        vector<int>temp(100001, 0);
        vector<vector<int>>ans;
        int n = matches.size();
        for(int i = 0; i < n;i++){
            temp[matches[i][1]] += 1;
        }
        for(int i = 0; i < 100001;i++){
            if(temp[i] == 1){
                losers.emplace_back(i);
            }
        }
        for(int i = 0; i < n;i++){
           if(temp[matches[i][0]] == 0){
               winners.emplace_back(matches[i][0]);
               temp[matches[i][0]] = 1;
           }
        }
        sort(winners.begin(), winners.end());
        sort(losers.begin(), losers.end());
        ans.emplace_back(winners);
        ans.emplace_back(losers);
        return ans;

    }
};
