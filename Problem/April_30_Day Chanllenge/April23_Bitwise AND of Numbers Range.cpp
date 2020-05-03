/*
    DateL: 4/23/2020
    a>>=1; equal to a=a>>1;
*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m==0){
            return 0;
        }else if(m==n){
            return n;
        }
        
        int count=0;
        while(m!=n){
            m=m/2;
            n=n/2;
            count++;
            if(m==0)return 0;
        }
        return m*pow(2,count);

    }
};