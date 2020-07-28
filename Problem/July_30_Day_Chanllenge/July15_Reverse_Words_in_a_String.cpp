/*
    Date: 2020/7/15
    Owner: Chun-Yeh, Lin
    Note: string::reverse_iterator rit = s.rbegin();
          s.pop_back();

*/

// Version 1
// Run Time: 24ms(35.14%) / Memory Usage: 7.5MB (78.80%)
class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        string temp_s = " ";
        char temp_c =' ';
        int l = s.length();
        
        // multiple words
        while(l>0){
            // find the char that is not nullspace
            temp_c = s[l-1];
            while(temp_c == ' ' && l>=1){
                l--;
                if(l>=1) temp_c = s[l-1];
                else break;
                // cout << "l: " << l << endl;
                // cout << "temp_c: " << temp_c << endl;
            }
            
            
            // deal with one word 
            while(temp_c != ' ' && l>=1){
                // cout << "temp_c: " << temp_c << endl;
                // cout << "l: " << l << endl;
                temp_s += temp_c;
                l--;
                if(l>=1)temp_c = s[l-1];

            }
            
            
         
            //cout << "temp_s: " << temp_s << endl;
            
            // add the word to the result
            if(temp_s.length()>1){
                for(string::reverse_iterator rit = temp_s.rbegin(); rit != temp_s.rend(); ++rit){
                    
                    result += *rit;
                }
            }

            //cout << "result: " << result << endl;
            
            //reset (add one nullspace)
            temp_s = " ";
        }
        
        if(result.size()>0)result.pop_back();
       
        return result;
    }
};