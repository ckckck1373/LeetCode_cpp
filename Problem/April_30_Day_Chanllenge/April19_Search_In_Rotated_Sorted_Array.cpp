/*
    Date: 4/25/2020
    2 version: 
        v1: just use find with iter..... bad QQ
        v2: if sorted -> pick one part go on
            if unsorted -> devide it and let both part go on 
    Time complexity: O(logn)
*/

// version1
class Solution {
public:
    int search(vector<int>& nums, int target) {
        vector<int>::iterator iter;
        iter=find(nums.begin(), nums.end(), target);
        if(iter==nums.end())return -1;
        else return iter - nums.begin();
             
    }
};



// version2

class Solution {
public:
    int result=-1;
    
    int search(vector<int>& nums, int target) {
        
        int left=0;
        int right = nums.size()-1;
        if(right==-1)return-1;
        else if(left==right){
            if(target == nums[0]) return 0;
            else return -1;
        }
        helper(nums, left, right, target);
        return result;
    }
    
    
    inline void helper(vector<int>& nums, int left, int right, int target){
        bool sorted=0;
        if(left==right){
            if( nums[left]==target){
                result=left;
                return; 
            }else{
                return;
            }
        }
        
        if(nums[left]<nums[right]){
            sorted=1;
        }else{
            sorted=0;
        }
        
        if(sorted){
            if(nums[(left+right)/2+1]<=target && target<=nums[right]){     
                helper(nums, (left+right)/2+1, right, target);
            }else{
                helper(nums, left, (left+right)/2, target);
            }
        }else{//unsorted
            helper(nums, left, (left+right)/2, target);
            helper(nums, (left+right)/2+1, right, target);
        }
    }
};
