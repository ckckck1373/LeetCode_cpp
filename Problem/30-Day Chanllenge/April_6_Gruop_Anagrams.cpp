/*
    Date: 4/8/2020
*/


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 2D vector
       
        
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
        
        vector<vector<string>> result(dict.size());
        int q=0;
        
//         for(iter=dict.begin();iter!=dict.end();iter++){
            
// //             // result[q].push_back(&(iter->second));
// //             // q=q+1;
//                 std::copy(*iter, result[q].begin());
//                 q+=1;
// //             // cout << iter->second[0] << endl;
            
//          }
        
        for(auto it_map=dict.cbegin();it_map!=dict.cend(); ++it_map){
            result[q].push_back(*it_map);
        }
        return result;
    }

};