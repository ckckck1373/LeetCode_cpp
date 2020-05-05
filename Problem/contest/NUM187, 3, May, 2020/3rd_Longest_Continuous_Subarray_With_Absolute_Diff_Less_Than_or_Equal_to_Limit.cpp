/*
    Date: 2020/5/5
    Note: Queue
    Owner: Chun-Yeh, Lin
*/
class Queue{
    public:
        int *array = new int[100000];
        int front, rear;
        int max_val;
        int min_val;
        int terms;
        
        Queue(void){
            front=0;
            rear=0;
            terms=0;
            max_val=INT_MIN;
            min_val=INT_MAX;
        }
    
        void Push(int x){
            
            max_val = max(x, max_val);
            min_val = min(x, min_val);
            array[rear]=x;
            rear = (rear+1)%100000;
            terms++;
        }
    
        void Pop(){
            if(terms>0){
              front = (front +1)%100000;
              terms--;  
            }else{
                cout << "POP at zero term" ;
            } 
        }
    
        void Check(){
            
            min_val = INT_MAX;
            max_val = INT_MIN;
            for(int i=0;i<terms;i++){
                min_val = min(array[front+i], min_val);
                max_val = max(array[front+i], max_val);
            }
        }
};


class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        Queue queue;
        int size = nums.size();
        int result=0;
        // queue.Push(nums[0]);

        for(int i=0;i<size;i++){
           
            
            queue.Push(nums[i]);
            // cout << "nums[i]: "<<nums[i] << "  ";

            while((queue.max_val-queue.min_val)>limit){
                // cout << "max1: " << queue.max_val << " ";
                // cout << "min1: " << queue.min_val << " ";
                queue.Pop();
                queue.Check();
                // cout << "max2: " << queue.max_val << " ";
                // cout << "min2: " << queue.min_val << " ";
            }
            // cout << " result: "<< result << endl;
            result = max(result, queue.terms);
        }
        return result;
        
    }
};