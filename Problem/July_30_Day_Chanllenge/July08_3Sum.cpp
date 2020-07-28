/*
    Date: 2020/7/8
    Owner: Chun_Yeh, Lin
    Note: ...annoying
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> result;
        vector<int> temp_set;
        vector<vector<int>>::iterator vec_iter;
        map<int, int> hashtable;
        map<int, int>::iterator iter;
       
         
        int p_sum = 0;
        int n = nums.size();
        // check trivial condition 
        if(nums.size()<3){
            return result;
        }
        
        // make hash table
        print_map(hashtable);
        hashtable.clear();
        for(int i=0;i<n;i++){
            iter = hashtable.find(nums[i]);
            if(iter==hashtable.end()){
                // not found
                hashtable.emplace(nums[i], 1);
            }else{
                //found
                iter->second++;
            }
        }
        print_map(hashtable);
        //print_map(hashtable); //for debugging
        
        
        
        // check special condition 
        if(hashtable[0]>2){
            temp_set.push_back(0);
            temp_set.push_back(0);
            temp_set.push_back(0);
            result.push_back(temp_set);
            temp_set.clear();
        }
        
        cout << "*****size: " << hashtable.size() << endl;
        
        // keep the first number in advance (i.e. it1->first)
        for(map<int, int>::iterator it1=hashtable.begin(); it1!=hashtable.end(); it1++){
            p_sum = - it1->first;
            temp_set.push_back(it1->first);
        
            it1->second--;
            
            cout << "-> first_num: " << it1->first << endl;
            cout << "temp_set[0]: " << temp_set[0] << endl;
            
            // keep the second number then and find the third number
            for(map<int, int>::iterator it2 = --hashtable.end(); it2!=it1; it2--){
                cout << "*******it2->first: " << it2->first << endl;
                it2->second--;
                
                
                iter = hashtable.find(p_sum-(it2->first));
                
                if((iter!=hashtable.end()) && (iter->second>0)){
                    // found
                    
                    temp_set.push_back(it2->first);
                    temp_set.push_back(iter->first);
                    cout << "it2->first " << it2->first << endl;
                    cout << "iter->first " << iter->first << endl ;
                    sort(temp_set.begin(), temp_set.end());
                    vec_iter = find(result.begin(), result.end(), temp_set); //
                    
                    if(vec_iter==result.end()){
                        // not found
                        cout << "new set! and its content: " << endl;
                        for(int q=0;q<3;q++)cout << temp_set[q] << " ";
                        result.push_back(temp_set);
        
                    }
                    temp_set.clear();
                    temp_set.push_back(it1->first);
                    
                }
                // cout << endl;
                
                it2->second++;
                
            }
            
            temp_set.clear();
            it1->second++;
        }
        
        return result;
    }
    
    void print_map(map<int, int>& map_in){
        cout << "here is map: " << endl;
        for(auto&u: map_in){
            cout << "value: " << u.first << endl;
            cout << "number: " << u.second << endl;
        }
    }
};