/*
    Date: 4/25/2020
*/


class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> zeros;
       
        int size = nums.size();
        int zero_size;

        for(int i=size-2;i>=0;i--){
            // print(zeros);
            zero_size = zeros.size();
            for(int j=0;j<zero_size;j++){
                if(nums[i]>zeros[j]+1){
                    zeros.erase(zeros.begin()+j);
                    j--;
                    zero_size--;
                }else{
                    zeros[j]++;
                }
                
            }
                
            
            if(nums[i]==0){
                zeros.push_back(0);
            }        
                
        }
        
        return (zeros.size()==0)? true:false;
    }
    
//     void print(vector<int>& array){
        
//         for(auto& it:array){
//             cout << it << ' ' ;
//         }
        
//     }
    
};