/*
    Date: 2020/7/22
    Owner: Chun-Yeh, Lin
    Note:  Recursion ->　just like the puzzle problem in DS class
*/


// version1: 
// Run time：56ms(81.24%) ; Memory Usage : 11.2MB(79.64%)　
struct Addr{
    int col;
    int row;
        
    Addr(int col_i, int row_i){
        col = col_i;
        row = row_i;
        
    }
};

typedef struct Addr Addr;


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool result = false;
        int rows = board.size();
        int cols = board[0].size(); 
        int len = word.length();
        
        // trivial check
        //cout << rows << " " << cols << " " << len << " ";
        if(len > rows*cols) return false;
        
        Addr addr(0, 0);
        
        for(int i=0;i<cols;i++){
            for(int j=0;j<rows;j++){
                if(board[j][i]==word[0]){
                    board[j][i] = '*';
                    //cout << "first point" << endl;
                    helper(board, word, cols, rows, result, addr, 1);
                    board[j][i] = word[0];
                }
                addr.row++;
            }
            addr.row=0;
            addr.col++;
        }
        
        
        return result;
    }
    
    void helper(vector<vector<char>>& board, string& word, int& cols, int& rows, bool& result, Addr addr, int ct){
        // debug

        // cout << "current_addr: " << " row: " << addr.row << " col: " << addr.col << endl;
        // cout << "ct: " << ct << endl;

        

        
        // terminate condition
        
        if(result==true)return;
        
        if(ct == word.length()){
            result = true;
            return;
        }
        
        // boundary condition
        
        //if(addr.col >= cols || addr.col < 0 || addr.row >= rows || addr.row < 0) return;
        

        
        // up : 0
        if(addr.row-1 >= 0 && board[addr.row-1][addr.col] == word[ct]){
            //cout << "go up " << endl;
            addr.row--;
            board[addr.row][addr.col] = '*';
            helper(board, word, cols, rows, result, addr, ct+1);
            board[addr.row][addr.col] = word[ct];
            addr.row++;
            
        }
            
        
        // down
        if(addr.row+1 < rows && board[addr.row+1][addr.col] == word[ct]){
             //cout << "go down " << endl;
            addr.row++;
            board[addr.row][addr.col] = '*';
            helper(board, word, cols, rows, result, addr, ct+1);
            board[addr.row][addr.col] = word[ct];
            addr.row--;
        }
            
        
        // left
         if(addr.col-1 >= 0 && board[addr.row][addr.col-1] == word[ct]){
              //cout << "go left " << endl;
             addr.col--;
             board[addr.row][addr.col] = '*';
             helper(board, word, cols, rows, result, addr, ct+1);
             board[addr.row][addr.col] = word[ct];
             addr.col++;
         }
            
        
        // right 
         if(addr.col+1 < cols && board[addr.row][addr.col+1] == word[ct]){
              //cout << "go right " << endl;
             addr.col++;
             board[addr.row][addr.col] = '*';
             helper(board, word, cols, rows, result, addr, ct+1);
             board[addr.row][addr.col] = word[ct];
             addr.col--;
             
         }
    }
};