class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string ans = "";
        int ones =0;
        int zeroes = 0;
        for(auto x : s){
            if(x == '0'){
                zeroes+=1;
            }
            else{
                ones+=1;
            }
        }
        while(ones>1){
            ans+='1';
            ones--;
        }
        while(zeroes){
            ans+='0';
            zeroes--;
        }
        if(ones){
            ans+='1';
        }
        return ans;
    }
};
