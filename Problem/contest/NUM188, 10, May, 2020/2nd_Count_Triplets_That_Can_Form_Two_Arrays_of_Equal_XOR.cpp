/*
    Date: 2020/5/11
    Owner: Chun-Yeh, Lin
    Note: i-j is actually the possibilities of answer
*/

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int result=0;
        int size = arr.size();
        vector<int> v;
        int v_size=0;
        for(int i=0;i<size;i++){
            //cout << "push in: "  << arr[i] << " ";
            v.push_back(arr[i]);
            for(int j=0;j<v_size;j++){
                v[j]^=arr[i];
                //cout << v[j] << " ";
                if(v[j]==0){                    
                    result = result+(i-j);
                }
            }
            v_size++;
            //cout << endl;
        }
        return result;
        
    }
};