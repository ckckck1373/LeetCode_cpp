
/*
    3/30/2020
    function: turn Roman into Integer form
    EX:
        Input: "LVIII"
        Output: 58
*/
class Solution {
public:
    int table(char x){
        switch(x){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return -1;
        }
    }
        
    int romanToInt(string s) {
        int size = s.size();
        int temp=0;
        int result=0;
        
        for(int i=size-1;i>=0;i--){
            if(i==size-1 || table(s[i])>=table(s[i+1])){
                temp = temp + table(s[i]);
            }else{
                temp = temp - table(s[i]);
            }
              
        
        }
        
        return temp;
       }
        
    
};