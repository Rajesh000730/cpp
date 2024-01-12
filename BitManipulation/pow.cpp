class Solution {
public:
   
    double myPow(double x, int num) {
        double res = 1;
        unsigned int n = num;
        if(num < 0){
            x = 1/x;
            n = -n;
        }
        if(x == 1) return 1;
        if(n == 0) return 1;
        while(n){
            if (n & 1){
                res *= x;
            } 
            x = x*x;
            n = n >> 1;
        }

        return res;
      
    }
};
