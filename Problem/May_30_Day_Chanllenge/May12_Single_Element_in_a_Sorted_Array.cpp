/*
    Date: 2020/5/12
    Owner: Chun-Yeh, Lin
    Note: 
*/

// Version2: Recursion w/o function
// Time Complexity: O(logn) 
// Space Complexity: O(1)




// Version1: Recursion w/ function
// Time Complexity: O(logn) 
// Space Complexity: O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int size = nums.size();
        int result=0;
        helper(nums, 0, size-1, result);  
        return result;
    }
    
    void helper(vector<int>& nums, int left,int right, int& result){
        int mid=(left+right)/2;
        if(mid%2==0){
            mid++;
        }
        if(left==right){
            result = nums[left];
            return;
        }
        
        if(nums[mid]==nums[mid+1]){
            helper(nums, left, mid-1, result);
        }else{  
            helper(nums, mid+1, right, result);
        }
    }
};