/*
    Date: 2020/5/3
    1437. Check If All 1's Are at Least Length K Places Away
*/

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int nums_size = nums.size();
        bool result=1;
        int temp=k;
        for(int i=0;i<nums_size;i++){
            //cout << "temp1: " << temp << endl;
            if(nums[i]==1){
                if(temp<k){
                    result = 0;
                    break;
                }
                
                temp=0;

            }else{
                // cout << "temp2: " << temp << endl;

                temp++;
            }
        }
        
        return result;
    }
};
