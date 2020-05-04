/*
    Date: 2020/5/4
    Note: can't not use ~num because it will return 2's complement value instead(ex: ~5=-6)
*/

class Solution {
public:
    int findComplement(int num) {
        if(num==0)return 1;
        int size = int(log2(num)+1);
        return (long long)pow(2, size)-num-1;
    }
};