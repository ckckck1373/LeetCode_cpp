/*
    Date: 2020/7/26
    Owner: Chun-Yeh, Lin
    Note: Time complexity : O(1)
*/


// version1 
// Runtime: 0 ms (100%)
// Memory Usage: 6.2 MB
class Solution {
public:
    int addDigits(int num) {
        if(num==0)return 0;
        int digit = int(log10(num)+1);
        int sum = 0;
        for(int i=0;i<digit;i++){
            sum += num%10;
            num = num/10;
            if(sum>9)sum = sum-9;
        }
        return sum;
    }
};