
/*
    Date: 2020/7/24
    Owner: Chun-Yeh, Lin
    Note: The key point is to differentiate the different between ans1 and ans2
*/


// version1
// Runtime: 20 ms
// Memory Usage: 10.1 MB
// Key: ans1 and ans2 have only one "1" in same spot, becasuse 1^0==1
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_info;
        xor_info = nums[0];
        int ans1 = 0;
        int ans2 = 0;
        
        for(int i=1;i<nums.size();i++){
            xor_info = xor_info ^ nums[i];
        }
        
        
        int bit_set = 0; 
        for(int i=0;i<32;i++){
            if(xor_info & (1 << i)){
                bit_set = i;
                break;
            }
        }
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] & (1 << bit_set)){
                ans1 ^= nums[i];
            }
        }
        
        ans2 = xor_info ^ ans1;
        
        return {ans1, ans2};
        
    }
};