/*
    Date: 4/18/2020
    
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        if(grid.empty()){
            return 0;
        }
        
        int y_size = grid.size();
        int x_size = grid[0].size();
        
        // first row
        for(int i=1;i<x_size;i++){
            grid[0][i] = grid[0][i-1] + grid[0][i];
        }
        // first col
        for(int i=1;i<y_size;i++){
            grid[i][0] = grid[i-1][0] + grid[i][0];
        }
        
        for(int i=1;i<y_size;i++){
           for(int j=1;j<x_size;j++){
               grid[i][j] = grid[i][j] + min(grid[i-1][j], grid[i][j-1]);
           } 
        }
        
        return grid[y_size-1][x_size-1];
    }
};









/*
    Version1 use Recurrsion to solve this question, but it always time exceed limit.(60/61)
    Because it check too many redundant path.
*/
class Solution {
public:
      
    int minPathSum(vector<vector<int>>& grid) {
        //special case
        if(grid.size()==0){
            return 0;
        }else if(grid.size()==1 && grid[0].size()==1){
            return grid[0][0];
        }
        
        int x=0;
        int y=0;
        int min=INT_MAX;  
        //right->1; down->0
        helper(min, x+1, y, grid[0][0], grid);
        helper(min, x, y+1, grid[0][0], grid);
        // cout << grid[0].size()-1 << endl;
        // cout << grid.size()-1 << endl;

        return min+grid[grid.size()-1][grid[0].size()-1];
    }
    
    inline void helper(int& min, int x, int y, int current_value, vector<vector<int>>& grid){
        if(x>grid[0].size()-1 || y>grid.size()-1 || current_value>min ){
            // terminate condition   
            return;
        }else if(x==grid[0].size()-1 && y==grid.size()-1){
            min = current_value;
            return;
        }
        current_value += grid[y][x];
        
        // cout << " x: "<< x;
        // cout << " y: "<< y ;
        // cout << " grid[y][x]: "<<grid[y][x] ;
        // cout << " current_value: "<<current_value <<endl;
        helper(min, x+1, y, current_value, grid);
        helper(min, x, y+1, current_value, grid);
    }
};