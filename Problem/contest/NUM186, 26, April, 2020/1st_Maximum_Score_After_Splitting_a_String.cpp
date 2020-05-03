class Solution {
public:
    int maxScore(string s) {
        int size = s.length();
        int result = INT_MIN;
        int num=0;
        int output=0;
        for(int i=0;i<size;i++){
            if(s[i]=='1'){
                num++;   
            }
        }
        result = num;
        for(int i=1;i<size;i++){
            result = num;
            for(int j=0;j<i;j++){
                if(s[j]=='0'){
                    result++;   
                }else if(s[j]=='1'){
                    result--;
                }
            }
            if(output<result){
                output =result;
            }
        }
        return output;
    }
};