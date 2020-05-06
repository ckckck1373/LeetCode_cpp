/*
    Date: 2020/5/6
    Owner: Chun-Yeh, Lin
    Note: 
        1. BFS
        2. temp.push_back({}); //add void vector<int> in vector<vector<int>>
        3. copy(it.rbegin(), it.rend(), back_inserter(result));
*/

// version3 : Buffer each diagonal and traverse
// BY huangdachuan @ Leetcode Discussion

#include <unordered_map>
#include <vector>
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int maxDiagonalId = 0;
        std::unordered_map<int, std::vector<int>> diagonalBuffer;
        for (std::size_t row = 0; row < nums.size(); ++row) {
            for (std::size_t column = 0; column < nums[row].size(); ++column) {
                const int diagonalId = row + column;
                maxDiagonalId = std::max(maxDiagonalId, diagonalId);
                diagonalBuffer[diagonalId].push_back(nums[row][column]);
            }
        }
        std::vector<int> result;
        for (int diagonalId = 0; diagonalId <= maxDiagonalId; ++diagonalId) {
            const auto& buffer = diagonalBuffer[diagonalId];
            for (auto iterator = buffer.rbegin(); iterator != buffer.rend(); ++iterator) {
                result.push_back(*iterator);
            }
        }
        return result;
    }
};



// version2 : List 
// BY Caspar-Chen-hku @ Leetcode Discussion
class Solution {
    public:
 vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        list<pair<int, vector<int>::iterator>> lst;

        size_t idx = 0;
        while(idx < nums.size() or lst.size()) {

            if(idx < nums.size()) {
                lst.emplace_front(idx, nums[idx].begin());
                ++idx;
            }

            auto lit = lst.begin();
            while(lit != lst.end()) {
                auto& [i, it] = *lit;
                ans.push_back(*it++);
				
                if(it == nums[i].end()) {
                    lit = lst.erase(lit);
                } else {
                    ++lit;
                }
            }
        }
        return ans;
    }
};




// version1
// Time Limit exceed... but function is correct
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int rows = nums.size();
        
        vector<int> result;
        vector<vector<int>> temp;
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<nums[i];j++){
                if(i+j==temp.size()){
                    // good way 
                    temp.push_back({});
                }
                temp[i+j].push_back(nums[i][j]); 
                
            }
        }

        for(auto& it: temp){
           copy(it.rbegin(), it.rend(), back_inserter(result));
           // insert each row of temp from right to left into result's tail
        }
        

  
        return result;
    }
};