/*
    Date: 2020/5/11
    Owner: Chun-Yeh, Lin
    Note: Use pass by reference while passing unchanged args to function is a lot efficient than pass by value.
          Ex: theColor, newColor... 
    
*/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        //vector<vector<int>> output;
        int rows = image.size();
        int cols = image[0].size();
        int theColor = image[sr][sc];
        if(theColor==newColor) return image;
        
        helper(image, sr, sc, rows, cols, newColor, theColor);
        return image;
        
    }
    
    void helper(vector<vector<int>>& image, int cur_r, int cur_c, int& rows, int& cols, int& newColor, int& theColor){
        if(cur_r>=rows || cur_r<0){
            return; 
        }else if(cur_c>=cols|| cur_c<0){
            return; 
        }
        //cout << "row: " << cur_r <<　" col: " << cur_c << endl;
        if(image[cur_r][cur_c]==theColor){
            image[cur_r][cur_c]=newColor;
            helper(image, cur_r+1, cur_c, rows, cols,newColor, theColor);
            helper(image, cur_r-1, cur_c, rows, cols,newColor, theColor);
            helper(image, cur_r, cur_c+1, rows, cols,newColor, theColor);
            helper(image, cur_r, cur_c-1, rows, cols,newColor, theColor);
        }

    }
};