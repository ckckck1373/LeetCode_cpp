/*
    Date : 4/9/2020
*/
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        vector<int> S_vec;
        vector<int> T_vec;
        int s_cnt, t_cnt;
        s_cnt=0;
        t_cnt=0;
        
        for(int i=0;i<S.length();i++){
   
            if(S[i]=='#'){
                if(S_vec.empty()) continue;
                S_vec.pop_back(); 
            }else{
                S_vec.push_back(int(S[i]));
            }
            
        }
        
        for(int i=0;i<T.length();i++){
            
            if(T[i]=='#'){
                if(T_vec.empty()) continue;
                T_vec.pop_back();
            }else{
                T_vec.push_back(int(T[i]));
            }
            
        }
        if(S_vec==T_vec){
            return true;
        }else{
            return false;
        }
        
        
        
    }
};

/*
    <inprovement>: This problem should be done with O(N) time complexity and O(1) space complexity, but I use more space.
                    So I improve my code under below with O(1) space complexity.

    <Note>
    1. vector can directly be compared
    2. continue means go to next loop condition
    3. x--; is acceptable
    
*/

/* Version 2*/
class Solution {
    public:
        bool backspaceCompare(string S, string T) {
            int k,p;
            /* key: k&p are responsible for remember the place where the next char should place .*/
            k=0;
            p=0;
            for(int i=0; i<S.length(); i++){
                if(S[i]=='#'){
                    k--;
                    k=max(0,k);
                }else{
                    S[k] = S[i];
                    k++;
                }
            }
            for(int j=0; j< T.length(); j++){
                if(T[j]=='#'){
                    p--;
                    p=max(0,p);
                }else{
                    T[p] = T[j];
                    p++;
                }
            }
            if(k!=p){
                return false;
            }else{
                for(int k=0;k<p;k++){
                    if(S[k]==T[k]){
                        continue;
                    }else{
                        return false;
                    }
                }
                return true;
            }
        }
};