//https://binarysearch.com/problems/Xor-Queries

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int m  = queries.size();
        vector<int>ans(m, 0);
        int n = arr.size();

        for(int i = 1; i < n; i++){
            arr[i] = arr[i] ^ arr[i-1];
        }
        for(int i = 0; i < m; i++){
            int l = queries[i][0];
            int h = queries[i][1];
            if(l == 0){
                ans[i] = arr[h];
            }
            else{
                ans[i] = arr[l - 1] ^ arr[h];
            }
            
        }
        return ans;
    }
};