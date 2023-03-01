#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>&Tasks) 
    {
        vector<int>ans;
        int taskptr=0,passedtime=0;
        vector<pair<int,pair<int,int>>>tasks;//enqueue time, {processing time, original index}
        for(int i=0;i<Tasks.size();i++)
        {
            tasks.push_back({Tasks[i][0],{Tasks[i][1],i}});
        }
        sort(tasks.begin(),tasks.end());
        passedtime+=tasks.front().first;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>priortasks;// processing time, {original index, enqueue time}
        while(taskptr<tasks.size())
        {
            if(priortasks.empty() && passedtime<tasks[taskptr].first)
            {
                passedtime=tasks[taskptr].first;
            }
            while(taskptr<tasks.size() && passedtime>=tasks[taskptr].first)
            {
                priortasks.push({tasks[taskptr].second.first,{tasks[taskptr].second.second,tasks[taskptr].first}});
                taskptr++;
            }
            ans.push_back(priortasks.top().second.first);
            passedtime+=priortasks.top().first;
            priortasks.pop();
        }
        while(!priortasks.empty())
        {
            ans.push_back(priortasks.top().second.first);
            priortasks.pop();
        }
        return ans;
    }
};