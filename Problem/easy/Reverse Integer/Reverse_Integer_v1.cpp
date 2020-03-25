
/*
    Description : Given a 32-bit signed integer, reverse digits of an integer.
    3/26/2020 version1 
    level: easy
    
*/
class Solution {
public:
    int reverse(int x) {
        char char_array[32];
        int output=0;
        int i=0;
        bool flag_overflow=false; // true for ~INT_MIN case
        

        if(x==INT_MIN){
            flag_overflow=true;
        }
        
        while(x>=10||x<=-10){
            char_array[i] = x%10;
            x=x/10;
            i=i+1;

        }
        
        char_array[i] = x%10;
        
        for(int j=0;j<i+1;j++){
            output = output + char_array[j] * pow(10,i-j);
        }
        
        if(flag_overflow==true){
            return 0;
        }else{
            return output;
        }
    }
};

/*
    Note: use too many memory 
    USE: 
        output= output*10 + x%10
    
*/