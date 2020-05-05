/*
    Date: 2020/5/5
    Owner: Chun-Yeh Lin
    Note: 
        1. Use hashmap(unordermap) is not efficiency enough(version1)
        2. int array[x]={0} // initailize all  garbage  with 0
*/


// version 2

// Time complexity : O(n) 
// Faster than 96.56%(w/ cin opti) 
//             56%   (w/o cin opti )

class Solution {
public:
    int firstUniqChar(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int array[26]={0};
        int result=0;
        for(char u: s){
            array[u-'a']++;
        }
        
        for(char u: s){
            if(array[u-'a']==1){
                return result;
            }
            result++;
        }  
        return -1;
    }
};



// Version 1: Can be improve by serching s string from input rather than use "find" 
// Time complexity : O(n) 
// Faster than 29.30% (w/o cin opti)
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int, int> map;
        unordered_map<int, int>::iterator iter;
        int size = s.length();
        int result=INT_MAX;
        for(int i=0;i<size;i++){
            iter = map.find(int(s[i]-'a'));
            if(iter==map.end()){
                //not find
                map.emplace(pair<int, int>(int(s[i]-'a'), i));
            }else{
                iter->second=INT_MAX;
            }
            //print(map);
            
        }
        for(auto& u:map){
            if(result>u.second){
                result = u.second;
            }
        }
        if(result==INT_MAX) return -1;
        return result;
    }
    
    void print(unordered_map<int, int>& map){
        for(auto& u:map){
            cout << u.first << "," ;
            cout << u.second << " " ;
        }
        cout << endl;
    }
};