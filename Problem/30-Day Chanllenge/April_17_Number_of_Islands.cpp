/*
    Date: 4/18/2020
    Recurrsion
*/

class Solution {
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int num=0;
        int x=0;
        int y=0;

        // special case
        if(grid.size()==0){
            return 0;
        }


        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1') num++;
                check(j, i, grid);
            }
        }
        
        return num;
    }
    
    void check(int x, int y, vector<vector<char>>& grid){

        if(y<0 || x<0 || y>grid.size()-1 || x>grid[0].size()-1 || grid[y][x]=='0'){
            // sea case or old land case
        }else{
            // new land case
            grid[y][x]='0';
            
            check(x+1, y, grid);
            check(x, y+1, grid);
            check(x-1, y, grid);
            check(x, y-1, grid);
        }

    }

    
};





/*
    Following code is version 1, which has poor efficiency.
    Because the function always find the new land from the beginning. 

*/


class Solution {
    
// struct Address{
//     int x;
//     int y;
// };
    
public:
//     Address* note;
    
    int numIslands(vector<vector<char>>& grid) {
        int num=0;
        int x=0;
        int y=0;

        // special case
        if(grid.size()==0){
            return 0;
        }else if(grid.size()==1){
            for(int i=0;i<grid[0].size();i++){
                if(grid[0][i]=='1' && (i+1==grid[0].size() || grid[0][i+1]=='0')){
                    num++;
                }   
            }
            return num;    
        }else if(grid[0].size()==1){
            for(int i=0;i<grid.size();i++){
                if(grid[i][0]=='1' && (i+1==grid.size() || grid[i+1][0]=='0')){
                    num++;
                }   
            }
            return num; 
        }
        
//         for ( const auto &row : grid ){
//            for ( const auto &s : row ) std::cout << s << ' ';
//            std::cout << std::endl;
//         }
//          cout << endl;
        
        while(1){
            find(x, y, grid);
            if(x==grid[0].size() && y==grid.size()-1){
                break;
            }else{
                // cout << "num: " <<num << endl;
                num++;
                check(x, y, grid);
            }
        }
        
        
        return num;
    }
    
    void check(int x, int y, vector<vector<char>>& grid){

        if(y>grid.size() || x>grid[0].size() || grid[y][x]=='0'|| grid[y][x]=='2'){
            // sea case or old land case
        }else{
            // new land case
            grid[y][x]='2';
            

            if(x==grid[0].size()-1){
                // right  case
                // cout << "x: " << x << " y: " << y << endl;
                check(x-1, y, grid);
                if(y!=grid.size()-1)check(x, y+1, grid);
                if(y!=0)check(x, y-1, grid);
            }else if(x==0){
                // left  case
                // cout << "x: " << x << " y: " << y << endl;
                check(x+1, y, grid);
                if(y!=grid.size()-1)check(x, y+1, grid);
                if(y!=0)check(x, y-1, grid);
            }else if(y==grid.size()-1){
                // buttom case
                // cout << "x: " << x << " y: " << y << endl;
                check(x+1, y, grid);
                check(x-1, y, grid);
                check(x, y-1, grid);
            }else if(x==0){
                // top case
                // cout << "x: " << x << " y: " << y << endl;
                check(x+1, y, grid);
                check(x, y+1, grid);
                check(x-1, y, grid);
            }else{
                // middle case
                // cout << "x: " << x << " y: " << y << endl;
                check(x+1, y, grid);
                check(x, y+1, grid);
                check(x-1, y, grid);
                check(x, y-1, grid);
            }
            
            // for ( const auto &row : grid ){
            //    for ( const auto &s : row ) std::cout << s << ' ';
            //    std::cout << std::endl;
            // }
            // cout << endl;

        }


    }
    
    void find(int &x, int &y, vector<vector<char>>& grid){
        x=0;
        y=0;
        while(x!=grid[0].size() && grid[y][x]!='1'){
            if(x==grid[0].size()-1 && y!=grid.size()-1){
                y++;
                x=0;
            }else{
                x++;
            }
        }

    }
    
};