/*
Date: 2020/6/13
Note: 
*/

// Version1: runtion:8ms / Memory Usage: 5.85 MB
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        
        for(int i=0;i<31;i++){
            
            if(n%2==1){
                result = (result+1);
            }
            n = n/2;
            result = result*2;
        }
        if(n==1)result++;
        return result;
        
    }
};

// Version2: Runtime: 0ms/Memory Usage: 5.9MB
// reduce if else statement
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0x0;
        uint32_t mask = 0x1;
        for(int i=0;i<31;i++){
            result = ((mask&n) + result) << 1;
            n = n >> 1;
        }
        if(n==1)result++;
        return result;
    }
};