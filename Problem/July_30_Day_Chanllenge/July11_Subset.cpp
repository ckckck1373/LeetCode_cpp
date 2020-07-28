/*
    Date: 2020/6/12
    Owner: Chun-Yeh, Lin
    Note:
*/

// version1: Runtime: 0ms(100%) / Memory Usage: 7.3MB(47.30%)
// Note: using binary representation as a mask to choose responding number can get the all possibilty of combinations.
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        vector<int> v;
        set<int> set_m;
        set<int>::iterator set_iter;
        int *arr;
        
        result.push_back(v); // add void vector
        
        // make set info
        for(int i=0;i<n;i++){
            set_iter = set_m.find(nums[i]);
            if(set_iter!=set_m.end()){
                // found;
            }else{
                // not found
                set_m.emplace(nums[i]);
            }
        }
        
        arr = new int [set_m.size()];
        set_iter = set_m.begin();
        
        for(int i=0;i<set_m.size();i++){
            arr[i] = *set_iter;
            set_iter++;
        }
        
        uint32_t mask = 1;
        int c=0;
        int temp_i;
        uint32_t temp;
        
        
        for(uint32_t i=1;i<pow(2, set_m.size()); i++){
            temp_i = i;
            while(temp_i>0){
                temp = mask & temp_i;

                if(temp){
                    v.push_back(arr[c]);
                }
                temp_i = temp_i >> 1;
                c++;
            }
                result.push_back(v);
                v.clear();
                c=0;
        }
    
        return result;
    }
};