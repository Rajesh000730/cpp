class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int row = 0;
        int prevcount = 0;
        for(string str: bank){
            int currcount = 0;
            for(char ch : str){
                if(ch=='1'){
                    ++currcount;
                }
            }
            if(currcount > 0){
                if(row > 0){
                    ans += prevcount*currcount;
                }
                row+=1;
                prevcount = currcount;
            }
        }
        if(row <= 1){
            return 0;
        }
        return ans;
    }
};
