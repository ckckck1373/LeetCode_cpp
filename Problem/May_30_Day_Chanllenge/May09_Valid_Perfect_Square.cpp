/*
    Date: 2020/5/9
    
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num<=0)return false;
        else if(num==1)return true;
        else if(num==2)return false;
        
        
        int test=num%10;
        if((test!=0)&&(test!=1 )&&(test!=4)&&(test!=5)&&(test!=6)&&(test!=9))return false;
        
        bool result=false;
        int up_bar=0;
        int down_bar=2;
        FindTopBar(up_bar, down_bar, num, result);
        return result;
        
    }

    void FindTopBar(int &up_bar, int& down_bar, int num, bool& result){
        while(true){
            if(num % down_bar==0){
                up_bar=num/down_bar;
                if(up_bar==down_bar){
                    result=true;
                    return;
                }
            }else if(down_bar>num/2){
                return;
            }
            //cout << "up_bar: " << up_bar << " down_bar: " << down_bar << endl;
            down_bar++;
        }
    }
};