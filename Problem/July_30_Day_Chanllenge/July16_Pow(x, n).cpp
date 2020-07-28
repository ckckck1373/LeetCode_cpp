/*
    Date: 2020/7/17
    Owner: Chun-Yeh, Lin
    Note: Version 1's  is terrible 
*/


// Version 1: Runtime: 132ms(0%) / Memory Usage: 6.1MB(30.39%)
class Solution {
public:
    double myPow(double x, int n) {
        double result = 1.0;

        if(n==0||x==1.00000){
            return 1.0;
        }else if(x==-1.00000){
            if(n&0x1)return -1.0;
            else return 1.0;
        }else if(n>0){
            for(int i=0;i<min(abs(n), 10000000);i++){
                result = result * x;
            }
        }else{
            for(int i=0;i<min(abs(n+1), 100);i++){
                result  = result *x;
                //cout << result << endl;
            }
            result = 1.0/(result*x);
        }
        
        return result;
        
    }
};