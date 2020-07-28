/*
    Date: 2020/7/20
    Owner: Chun-Yeh, Lin
    Note:
*/

//Version1: Runtime: 8ms(45.83%)/Memory Usage: 6.6MB(43.90%)
class Solution {
public:
    string addBinary(string a, string b) {
        int a_v = 0;
        int b_v = 0;
        int s_v = 0;
        int a_l = a.length();
        int b_l = b.length();
        string result;
        
        for(int i=0; i < max(a_l, b_l); i++){
            
            if(i < a_l && a[a_l-i-1]=='1')a_v = 1;
            else a_v = 0;
            
            if(i < b_l && b[b_l-i-1]=='1')b_v = 1;
            else b_v = 0;
            
            s_v = a_v + b_v + s_v;
            //cout << " a_v: " << a_v << " b_v: " << b_v << " s_v: " << s_v << endl;
            if(s_v == 0 || s_v==2)result.insert(result.begin(), '0');
            else result.insert(result.begin(), '1');
            s_v = s_v >> 1;
        }
        
        if(s_v==1)result.insert(result.begin(), '1');
        
        return result;
    }
};