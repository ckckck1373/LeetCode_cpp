/*
    Date: 4/24/2020
    
*/


/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        
        int value=0;
        
        int rows = binaryMatrix.dimensions()[0];
        int cols = binaryMatrix.dimensions()[1];
        
        int current_row=0;
        int current_col=cols-1;
 

        for(int i=0;i<rows+cols-1;i++){
            value = binaryMatrix.get(current_row, current_col);
            if(value==1){
                current_col--;
            }else{
                current_row++;
            }
            if(current_col==-1){
                return 0;
            }else if(current_row==rows){
                return (current_col==cols-1)? -1: current_col+1;
            }
           
        }
        return 0;

    }
};