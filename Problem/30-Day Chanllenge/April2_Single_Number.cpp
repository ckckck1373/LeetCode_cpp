
/*
    4/2/2020
    Given a non-empty array of integers, every element appears twice except for one. Find that single one.
    ex: 
        Input: [2,2,1]
        Output: 1
*/
#include <algorithm>
#include <vector>

class Solution {
public:

    
    int singleNumber(vector<int>& nums){
        sort(nums.begin(), nums.end());
//         for(int i=0;i<nums.size();i++){
//             cout << nums[i] << " "; 
//         }
     
        for(int i=0;i<nums.size();i+=2){
            if(i<(nums.size()-1)){
                if(nums[i]!=nums[i+1]){
                    return nums[i];
                }
            }else{
                return nums[i];
            }

        }
        return -1;
    }
};

/*
    result ^= num[i]; <- only the isolated term remain .
*/