/*
    Date: 2020/5/11
    Owner: Chun-Yeh, Lin
    Note: Stack
*/

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        int keep=0;
        int size=target.size();
        for(int i=1;i<=n;i++){
            if(target[keep]!=i){
                result.push_back("Push");
                result.push_back("Pop");
            }else{
                result.push_back("Push");
                keep++;
                if(keep==size){
                    break;
                }
            }
        }
        return result;
    }
};