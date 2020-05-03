/*
    Date: 4/16/2020
    Spec: 
        time: O(n)
        space: O(1)
    
       
*/



class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product_keep=1;
        vector<int> ans(nums.size(), 1); 
        
        for(int i=0;i<nums.size()-1;i++){
            product_keep=product_keep*nums[i];
            ans[i+1]=ans[i+1]*product_keep;
        }
        
        product_keep=1;
        for(int i=nums.size()-1;i>0;i--){
            product_keep=product_keep*nums[i];
            ans[i-1]=ans[i-1]*product_keep;
        }

        return ans;
    }
};



// version1: time complexity is high O(n^2);
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         //int tail=0;
//         int size=nums.size();
//         vector<int> ans;
//         ans.push_back(nums[1]);
//         ans.push_back(nums[0]);
    
//         for(int j=0;j<size-2;j++){
//             //tail=nums[j+2];
//             // temp=ans[j+1];
//             ans.push_back(nums[j+1]*ans[j+1]);
//             for(int i=0;i<ans.size()-1;i++){
//                 ans[i]=ans[i]*nums[j+2];
//             }
            
//         }
        

//         return ans;
//     }
// };