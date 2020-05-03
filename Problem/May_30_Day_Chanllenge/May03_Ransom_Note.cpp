/*
    Date: 5/3/2020
    
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;
        for(char u: ransomNote){
            map[u]++;
        }
        
        for(char u: magazine){
            if(map[u]>1){
                map[u]--;
            }else{
                map.erase(u);
            }
        }
        return map.empty();
    }
    

};




// use vector is faster

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.size();
        if(n == 0) return true;
        if(n >= magazine.size()) return false;
        vector<int> cnt(26, 0);
        for(auto ch : ransomNote){
            cnt[ch-'a']++; //save char as int(ASCII code)
        }
        for(auto ch : magazine){
            cnt[ch-'a']--;
        }
        for(auto i : cnt){
            if(i>0) return false;
        }
        return true;
    }
};