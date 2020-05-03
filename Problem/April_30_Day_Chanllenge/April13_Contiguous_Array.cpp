/*
    Date: 4/26/2020
    
*/



class Solution {
public:
    inline int findMaxLength(vector<int>& nums) {
        if(nums.empty()==1){
            return 0;
        }
        unordered_map<int, int> footprint;
        footprint.emplace(0,-1);
        unordered_map<int, int>::iterator it1;
        int sum = 0;
        int size = nums.size();
        int result=0;
        for(int i=0;i<size;i++){
            if(nums[i]==0){
                sum--;
                it1 = footprint.find(sum);
                
                if(it1!=footprint.end()){
                    if(result < i - it1->second){
                        result = i - it1->second;
                    }
                }else{
                    footprint.emplace(sum, i);
                }

            }else{
                // nums[i]==1
            
                sum++;
                it1 = footprint.find(sum);
               
                if(it1!=footprint.end()){
                    if(result < i - it1->second){
                        result = i - it1->second;
                    }
                }else{
                    footprint.emplace(sum, i);
                }
            }
        }

        return result;
    }
    
    // inline void print(unordered_map<int, int>& footprint){
    //     for(auto& u: footprint){
    //         cout << "first" << u.first << " " ;
    //         cout << "second" << u.second << " " ;
    //     }
    //     cout << endl;
    // }
};