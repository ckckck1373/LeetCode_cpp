/*
    Date: 2020/5/9
    Owner: Chun-Yeh, Lin
    Note: Stirng 
*/

// version1 
// Time complexity: O(n)

class Solution {
public:
    string reformat(string s) {
        string str_al;
        string str_num;
        int num_al=0;
        int num_num=0;
        
        int num = s.length();
        for(char u: s){
            if(int(u)>=97){
                str_al += u;
                num_al++;
            }else{
                str_num += u;
                num_num++;
            }
        }
        string result="";
        if(abs(num_al-num_num)>1){
            return result;
        }else{
            if(str_al.length()>str_num.length()){
                for(int i=0;i<(num+1)/2;i++){
                    result += str_al[i];
                    if(str_num[i]>47)
                        result += str_num[i];
                }
            }else{
                for(int i=0;i<(num+1)/2;i++){
                    result += str_num[i];
                    if(str_al[i]>96)
                        result += str_al[i];
                }
            }
            
        }
        
        return result;
    }
};