class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int countlow = 0;
        int counthigh = 0;
        int x = low;
        int y = high;
        vector<int>vec;
        while(x){
            ++countlow;
            x = x/10;
        }
        while(y){
            ++counthigh;
            y = y/10;
        }
        for(int i = 1; i <= 10 - countlow;i++){
            int x = 0;
            for(int j = i; j < countlow+i && j < 10;j++){
                x = x*10 + j;
                
            }
            if(x > high) break;
            if(x >= low) vec.push_back(x);
            if(i == 10-countlow && countlow < counthigh){
                countlow+=1;
                i = 0;
            }
        }
        return vec;
    }
};
