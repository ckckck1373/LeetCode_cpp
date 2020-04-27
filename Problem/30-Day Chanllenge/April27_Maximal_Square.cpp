/*
    Date: 4/28/2020
    Dp question
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
       
        int rows = matrix.size(); 
        if(rows==0)return 0;
        int cols = matrix[0].size();
        
        int **dp = new int*[rows];
        for(int i=0;i<rows;i++){
            dp[i] = new int[cols];
        }
        int temp=0;
        int result =0;
        for(int i=0;i<cols;i++){
            if(matrix[0][i]=='1'){
                temp=1;
                result=1;
            }
            else temp=0;
            dp[0][i] = temp;
        }
        for(int i=0;i<rows;i++){
            if(matrix[i][0]=='1'){
                temp=1;
                result=1;
            }
            else temp=0;
            dp[i][0] = temp;
        }
        
        int min_value=0;
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                
                if(matrix[i][j]=='1')temp=1;
                else temp=0;

                if(matrix[i][j]=='1'){
                    if(dp[i-1][j]!=0 && dp[i][j-1]!=0 &&dp[i-1][j-1]!= 0){
                        min_value = min(dp[i-1][j], dp[i][j-1]);
                        min_value = min(min_value,dp[i-1][j-1]);
                        dp[i][j] = min_value+1;
                        if( result<min_value+1){
                            result = min_value+1;
                        }
                    }else{
                        dp[i][j] = 1;
                        if( result==0){
                            result = min_value+1;
                        }
                    }
                        
                     
                }else{
                     dp[i][j] = 0;
                }

            }
        }

        return pow(result,2);

    }
};