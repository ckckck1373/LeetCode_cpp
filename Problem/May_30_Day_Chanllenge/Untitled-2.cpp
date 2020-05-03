class Solution {
public:
    int* cols;
    int rows;
    int cols_max=0;
    int total_num=0;
    
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        
        rows = nums.size();
        if(rows==1) return nums[0];
        
        cols = new int[rows];

        vector<int> result;
        for(int i=0;i<rows;i++){
            cols[i] = nums[i].size();
            total_num += cols[i];
            if(cols_max<cols[i]) cols_max=cols[i];
        }
        // cout << cols_max << " ";
        // cout << total_num << " ";
        
        helper(result, nums, 0, 0);
        return result;
    }
    
    void helper(vector<int>& result, vector<vector<int>>& nums, int col, int row){


        if( rows>row && row>=0 && col>=0 &&  cols[row]>col  ){
            // exist
            result.push_back(nums[row][col]);
            //cout << "total_num "<< total_num << endl;
            total_num--;   
            if(total_num==0)return;
        }
        
        //cout << row << " " << col << endl;
        // find next
        if(row==0 && (row+col)<max(rows, cols_max)){
            helper(result, nums, 0, col+1);
        }else if(col==cols_max-1){
            helper(result, nums, (col+row+2-rows), rows-1);
        }else{
            helper(result, nums, col+1, row-1);
        }

        

    }
};