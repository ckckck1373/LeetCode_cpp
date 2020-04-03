/*
	Date: 4/3/2020
	
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int total_sum=nums[0];
        
        //initialize
        if(nums.size()==1){
            return total_sum;
        }
        
        while(nums[0]<=0){
            nums.erase(nums.begin());   
            total_sum = (total_sum < nums[0])? nums[0]: total_sum;
            if(nums.size()==1){
                 return total_sum;
            }
        }
        
        int left_start=0;
        int left_local_max_address=0;
        int left_local_max_value=nums[0];
        int left_current_value=nums[0];
        
        total_sum=nums[0];
        for(int i=0;i<nums.size()-1;i++){
            // left side
            if(left_current_value<1){
                left_start=i+1;
                left_current_value=nums[left_start];
            }else if(left_current_value+nums[i+1]<1){
                left_start=i+1;
                left_current_value=nums[left_start];
            }else{
                left_current_value=left_current_value + nums[i+1];
            }
            
            if(left_local_max_value<left_current_value){
                left_local_max_value = left_current_value;
                left_local_max_address = left_start;
            }

        }
        return left_local_max_value;
    }
};