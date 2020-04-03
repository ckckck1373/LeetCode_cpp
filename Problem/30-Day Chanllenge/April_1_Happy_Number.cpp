/*
    4/2/2020
    Description:　A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

*/
class Solution {
public:
    int routine=0;
    int square_table(int x){
        switch(x){
            case 1: return 1;
            case 2: return 4;
            case 3: return 9;
            case 4: return 16;
            case 5: return 25;
            case 6: return 36;
            case 7: return 49;
            case 8: return 64;
            case 9: return 81;
            default: return 0;
        }
    }
    bool isHappy(int n) {
        
        long long next_num = 0;
        while(n>0){
            next_num = next_num + square_table(n%10);
            n=n/10;         
        }
        
        if(routine>500){
            routine=0;
            return false;
        }else if(next_num>1){
            routine += 1;
            return isHappy(next_num) ;
        }else{
            routine=0;
            return true;
        }
    }
};

/*
    Actually, I didn't solve this problem perfectly, because the question usually need to save every numbers which it had calculated. 
    However, I bet that if the number of the loop exceeded 500, the number was not Happy Number.
*/