/*
    Date: 4/26/2020
    #DP problem
*/

class Solution {
public:
    inline int longestCommonSubsequence(string text1, string text2) {
        int text1_length=text1.length();
        int text2_length=text2.length();
        int** dp;
        if(text1_length==0 || text2_length==0)return 0;
        else{
            
            dp = new int*[text2_length];
            for(int i=0;i<text2_length;i++){
                dp[i] = new int[text1_length];
            }
            
            dp[0][0] = (text1[0]==text2[0]);
            for(int i=1;i<text1_length;i++){
                if(text2[0]==text1[i]) dp[0][i]=1;
                else dp[0][i]=dp[0][i-1];

            }
            for(int j=1;j<text2_length;j++){
                if(text1[0]==text2[j]) dp[j][0]=1;
                else dp[j][0]=dp[j-1][0];

            }
            for(int row=1;row<text2_length;row++){
                for(int col=1;col<text1_length;col++){
                    if(text1[col]==text2[row]){
                        dp[row][col] = dp[row-1][col-1] + 1;
                    }else{
                        dp[row][col] = max(dp[row-1][col], dp[row][col-1]);
                        
                    }

                }
            }
            
            
        }

        return dp[text2_length-1][text1_length-1];
    }
};

