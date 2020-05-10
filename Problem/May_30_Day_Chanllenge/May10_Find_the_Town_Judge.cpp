/*
    Date: 2020/5/10
    Owner: Chun-Yeh, Lin
    Note: Version1 's performance is poor 
*/

// Version2: array
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if(N==1)return 1;
        int array[1000]={0};
        int result=-1;
        bool flag=0;
        int size = trust.size();
        for(int i=0;i<size;i++){
            array[trust[i][1]-1]++;
            array[trust[i][0]-1]--;
        }
        //cout << array[1] << endl;
        //cout << size << endl; 
        for(int i=0;i<N;i++){
            // cout << "i: " << i ;
            // cout << " array " << array[i] << endl;
            if(flag==0 && array[i]==N-1){
                result= i+1;
                flag=1;
            }else if(flag==1 && array[i]==N-1){
                result=-1;
            }
        }
        return result;
        
    }
};


// Version1: unordered_map(Hash Map) : Poor performance
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
    
        int relation = trust.size();
        if(N==1){
            return 1;
        }
        unordered_map<int, int> map;
        unordered_map<int, int>::iterator iter;
        for(int i=0;i<relation;++i){
            iter = map.find(trust[i][1]);
            if(iter!=map.end() && iter->second>0){
                // found
                iter->second++;
            }else{
                // not found
                map.emplace(pair<int, int>(trust[i][1], 1));
            }
            map[trust[i][0]]=-1;
                
        }
        
        int result=-1;
        for(auto& u:map){
            // cout << "u.first: " <<　u.first << " ";
            // cout << "u.second: " << u.second << endl;
            if(result<0 && u.second==N-1){
                result=u.first;
            }else if(u.second==N-1){
                result=-1;
            }
        }
        
        
        return result;
    }
};