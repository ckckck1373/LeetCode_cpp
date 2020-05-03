/*
    Date: 4/25/2020
    For each asterisk, they will affect their neighbor become a possible solution.
    The vector should only save 1/0 to check if it was exist.
    The index of vector is always positive(with zero) because we don't need to concerned about negative case( ) is more then (+* )
    In the end, array[0] will be the result for this string can be valid or not.
*/

class Solution {
    
public:
    bool checkValidString(string s) {
        int nums = s.length();
        vector<int> array;
        vector<int>::iterator iter;

        
        int sum=0;
        bool result=0;
        bool flag=0;
        char temp;
        array.push_back(1);

        for(int i=0;i<nums;i++){
            temp = s[i];
            helper(temp, array, flag);
        }
        
        if(array[0]==1){
            return true;
        }else{
            return false;
        }

    }
    
    void print(vector<int>& array, char temp){
        for(auto& it:array){
            std::cout << it << ' ';
            
        }
        cout << temp;
        cout << endl;
    }
    
    inline void helper(char char_in, vector<int>& array, bool& flag){
        int array_size=array.size();
        if(char_in=='('){
            for(int i=array_size-1;i>=0;i--){
                if(i==array_size-1){
                    if(array[i]==1){
                        array[i]=0;
                        array.push_back(1);
                        array_size++;
                    }
                }else{
                    if(array[i]==1){
                        array[i+1]=1;
                    }
                    array[i]=0;
                }
            }  
        }else if(char_in==')'){
            for(int i=0;i<array_size;i++){ 
                if(i==0){
                    if(array[i]==1){
                        array[i]=0;
                    }
                }else{
                    if(array[i]==1){
                        array[i-1]=1;
                    }
                    array[i]=0;
                }
            }
        }else{
            // * case
            for(int i=0;i<array_size;i++){
                if(array[i]==1){
                    if(i==0) {
                        if(array_size==1)array.push_back(1);
                        else array[1]=1;
                    }else if(i==array_size-1){
                        array[i-1]=1;
                        array.push_back(1);
                    }else{
                        array[i-1]=1;
                        array[i+1]=1;
                        i++;
                    }
                }
            }
        }
        
    }
    
};
