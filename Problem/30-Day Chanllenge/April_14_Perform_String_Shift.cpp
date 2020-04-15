/*
    Date: 4/15/2020
    string.append & string.assign
*/

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
    int start=0;
        
        for(int i=0;i<shift.size();i++){
            if(shift[i][0]==1){
                start=start-shift[i][1];    
            }else{
                start=start+shift[i][1];
            }
        }
        
        
        while(start<0 || start>s.length()){
            if (start<0){
                start = start+s.length();
            }else{
                start = start-s.length();
            }
        }
        // cout << shift.size() << endl;
        // cout << s.length() << endl;
        // cout << start << endl;
        
        string ans;
        ans.assign(s, start, s.length()-start);
        ans.append(s, 0, start);
        return ans;
    }
};