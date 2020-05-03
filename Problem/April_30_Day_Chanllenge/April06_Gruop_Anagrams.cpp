/*
    4/9/2020
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>>dict;
        map<vector<int>, vector<string>>::iterator iter;
        
        vector<int> temp;
        vector<string> temp_string;
        for(int i=0;i<strs.size();i++){
            for(int j=0;j<strs[i].size();j++){
                temp.push_back(int(strs[i][j]));
            }
            sort(temp.begin(), temp.end());
            
            iter = dict.find(temp);
  
            if(iter!=dict.end()){
                // find
                dict[temp].push_back(strs[i]);

            }else{
                // not find
                temp_string.push_back(strs[i]);
                dict.insert(pair<vector<int>, vector<string>>(temp, temp_string));
            }
            temp.clear();
            temp_string.clear();
        }
        
        vector<vector<string>> result;

        for(iter=dict.begin();iter!=dict.end();iter++){ 
            result.push_back(iter->second);
            
         }
        

        return result;
    }

};