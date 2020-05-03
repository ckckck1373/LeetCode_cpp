/*
    Date: 5/3/2020
    1436. Destination City
*/
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int size = paths.size();

        unordered_map<string, string> map;
        unordered_map<string, string>::iterator iter;
        string result;
    
        for(int i=0;i<size;i++){
            map.emplace(pair<string, string>(paths[i][0], paths[i][1]));  
        }
        // cout << paths[2][1];
        // cout << map[paths[2][1]];
        iter = map.find(paths[0][0]);
        
        for(int i=0;i<size;i++){
            if(iter!=map.end()){
                //cout << paths[i][1] << " " ;
                iter = map.find(paths[i][1]);
                result = paths[i][1];
            }else{
                break;
            }
            //cout << result;
        }
        return result;
    }
};