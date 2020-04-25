/*
    Date: 4/7/2020
    
*/

class Solution {
public:
    int countElements(vector<int>& arr) {
        map<int, int>mapInt;
        map<int, int>::iterator iter;

        int result=0;
        for(int i=0;i<arr.size();i++){
            iter = mapInt.find(arr[i]);
            if(iter!=mapInt.end()){
                // find
                mapInt[arr[i]] += 1;
            }else{
                // not find
                mapInt.insert(pair<int, int>(arr[i], 1));
            }

        }
        for(int j=0;j<1000;j++){
            if(mapInt[j]!=0 && mapInt[j+1]!=0){
                result = result + mapInt[j];
            }else{
                continue;
            }
        }
        return result;

    }
};