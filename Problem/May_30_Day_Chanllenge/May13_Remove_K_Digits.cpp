/*
    Date: 2020/5/13
    Owner: Chun-Yeh, Lin
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        int len=num.size();
        if(len==k)return "0";
        int cur_addr=0;
        //int check_addr=0;
        while(k!=0){
            
            if(cur_addr>=0 && cur_addr!=len-1 && num[cur_addr]>num[cur_addr+1]){
                num.erase(num.begin()+cur_addr);
                len--;
                k--;
                cur_addr--;
            }else if(cur_addr+k>=len){
                num.erase(num.begin()+cur_addr);
                len--;
                k--;
                cur_addr--;
            }else{
                cur_addr++;
            }
            
           // cout << num << endl;
           //  cout << "cur_addr: " << cur_addr ;
           //  cout << "  k: " << k ;
        }
        
        while(num[0]=='0' && len!=1){
            num.erase(num.begin());
            len--;
        }
        return num;
    }
};

static auto fastio = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();