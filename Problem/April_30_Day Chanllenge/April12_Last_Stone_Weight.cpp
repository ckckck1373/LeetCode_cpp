/*
    Date : 4/12/2020
    Heap
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int max_1=0;
        int max_2=0;
        make_heap(stones.begin(), stones.end());

         while(stones.size()>1){
            max_1 = stones.front();       
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
 
            max_2 = stones.front();       
            pop_heap(stones.begin(), stones.end());
            stones.pop_back(); 
    
            if(max_1>max_2){
                stones.push_back(max_1-max_2);
                push_heap(stones.begin(), stones.end());
            }
        
        }
        
        
        return (stones.size()==0)? 0:stones.front();
    }
};



/*
    when vector.size()=0 ,vector.front() is not 0 (is the last time value)
    Hence, when it comes to return value.
    We should use accululate function: 
        std::accumulate(first, last, init);
    
*/