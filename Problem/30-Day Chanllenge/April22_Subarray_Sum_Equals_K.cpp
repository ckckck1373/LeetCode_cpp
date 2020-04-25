/*
    Date: 4/23/2020
    Maybe it is better that use unorder map to solve this question.
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int temp_sum=0;
        int* sum_array = new int[nums.size()+1];
        int result=0;
        sum_array[0]=0;
        for(int i=1;i<=nums.size();i++){
            temp_sum = temp_sum + nums[i-1];
            sum_array[i] = temp_sum;
        }

        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size()+1;j++){
                if(sum_array[j]- sum_array[i]==k){
                    result++;
                }
            }
        }
        return result;
  
    }
};

// version 2(use iter and .second)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        unordered_map<int, int> sum_map;
        sum_map.emplace(0, 1);
        unordered_map<int, int>::iterator iter, iter1;

        int num_subarray=0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            iter = sum_map.find(sum-k);
            iter1 = sum_map.find(sum);


            if(iter!=sum_map.end()){
                num_subarray += iter->second;
            }
            
            if(iter1==sum_map.end()){
                sum_map.emplace(sum, 1);
            }else{
                iter1->second++;
            }
        }

        return num_subarray;
    }
};


// version 3  : hash table、unordered map
//記錄每一個從頭開始算的sum，如果剛好有特定可以砍掉的頭，即是result++(這個map沒有在開頭塞0，所以要判斷sum是否就等於k)


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        int cur_sum=0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            cur_sum+=nums[i];
            if(cur_sum==k){
                ans++;
            }
            if(m.find(cur_sum-k)!=m.end()){ // use find can avoid using iter
                ans+=m[cur_sum-k];
            }
            m[cur_sum]++; // unordermap can use [] find the key and directly use it even if the key haven't been the dictionary()
        }
        return ans;
    }
};