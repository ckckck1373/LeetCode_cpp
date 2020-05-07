/*
    Date: 2020/5/7
    Owner: Chun-Yeh, Lin
    
*/

class Solution {
public:
    int current_max=INT_MIN;
    void helper(vector<int>& temp, int count, int k, int my_max, int addr){
        if(addr==count){
            current_max = max(current_max, my_max);
            return;
        }
        for(int i=1;i<k+1;i++){
            if(addr+i<=count){
                helper(temp, count, k, my_max+temp[addr+i], addr+i);
            }
        }
        
    }
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int num_vector = nums.size();
        vector<int> temp;
        int sum=0;
        int count=0;
        int max_element=INT_MIN; 
            
        for(int i=0;i<num_vector;i++){
            if(nums[i]<0){
                if(i==num_vector-1){
                    if(count==num_vector-1)return max_element;
                }else{
                    temp.push_back(nums[i]);
                    max_element = max(max_element, nums[i]);
                    count++;
                }

            }else if(nums[i]>=0 && count>=k){
                current_max=INT_MIN;
                temp.push_back(0);
                helper(temp, count, k, 0, -1);
                if(sum>abs(current_max)){
                    sum+=current_max;
                }else{
                    sum=0;
                }
                sum+=nums[i];
                temp.clear(); 
                count=0;
            }else{
                temp.clear(); 
                sum+=nums[i];
                count=0;
                max_element= INT_MIN;
            }    
        }
        return sum;
    }
};