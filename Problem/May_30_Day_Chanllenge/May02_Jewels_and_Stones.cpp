/*
    Date: 5/2/2020
    # string iter
    # map['*'] act like count
*/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, int> map;
        int result =0;
        for(char i: J){
            map[i]++;
        }
        for(char j: S){
            if(map.count(j)>0)
                map['*']++;
        }
        return map['*'];
    }
};