/*
    Date: 2020/5/1
*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long left=1;
        long long right = n;
        int result=0;
        helper(left, right, result);
        return result;
    }
    inline void helper(long long left, long long right, int& result){
        if(left==right){
            result = left;
            return;
        }
        long long mid = (left+right)/2;
        //cout << "left: " << left << " right: " << right <<  " mid: " << mid << endl;
        if(isBadVersion(mid)==false){
            if(isBadVersion(mid+1)==true){
                result = mid+1;
                return;
            }
            left = mid;
            helper(left, right, result);
        }else{
            //mid==1
            if(isBadVersion(mid-1)==false){
                result = mid;
                return;
            }
            right = mid;
            helper(left, right, result);
        }
    }
};