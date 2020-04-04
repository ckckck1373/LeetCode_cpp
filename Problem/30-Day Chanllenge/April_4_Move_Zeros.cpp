/*
    Date: 4/4/2020
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nums_zeros=0;

        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                nums.erase(nums.begin()+i);
                i=i-1;
                nums_zeros= nums_zeros + 1;
            
            }
        }
       
        for(int j=0;j<nums_zeros;j++){
            nums.push_back(0);
    }
    }
};