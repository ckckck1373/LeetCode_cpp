/*
    Date: 2020/5/6
    Owner: Chun-Yeh, Lin
    
*/

// version2: vote (smarter way)
// Note: Because the numbers of ans must bigger than the half of vector, 
//       that is to said, no one will suvive even if than cancel the ans one by one 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int vote=0;
        int num_vote=0;
        for(auto& u:nums){
            if(num_vote==0){
                vote = u;
            }
            
            if(vote!=u)num_vote--;
            else num_vote++;
        }
        return vote;

        
    }
};




// version1: hash map 
// Time complexity: O(n)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int, int> map;
        for(int i=0;i<size;i++){
            map[nums[i]]++;
            if(map[nums[i]]>size/2) return nums[i];
        }
        return -1;
    }
};