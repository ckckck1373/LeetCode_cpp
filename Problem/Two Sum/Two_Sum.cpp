/* 3/23/2020
    Given an array of integers, return indices of the two numbers such that they add up to a specific target.
    You may assume that each input would have exactly one solution, and you may not use the same element twice.
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       for(size_t i=0;i<nums.size();i++){
           for(size_t j=i+1;j<nums.size();j++){
               // auto temp1 = nums[j];
               // auto temp2 = nums[i];
               if((nums[i] + nums[j]) == target){
                   return {(int)i, (int)j};
               }else{
                   continue;
               }
           }
       }
       return vector<int>();
    }
};

/*
    Runtime: 464ms(5.72%)
    Memory Usage 7MB(100.0%)
*/


/*
    Other's code
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(size_t i = 0; i < nums.size(); ++i) {
            map.emplace(std::make_pair(nums.at(i),i));
        }
        for(size_t i = 0; i < nums.size(); ++i) {
            const auto mit = map.find(target - nums.at(i));
            if(mit != map.end() && (int)i != mit->second) {
                return {(int)i, mit->second};
            }
        }
        return vector<int>();
    }
};

