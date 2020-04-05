/*
    Date: 4/5/2020
    Note: Remember to check vector's boundary
        Ex:prices.empty()==1 ....
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int current_earn=0;
        int buy_price=0;
        int current_day=0;
        bool state=0;
        if(prices.size()==0){
            return 0;
        }
        while(current_day < prices.size()-1){     
            if(state==0){
                if(prices[current_day]<prices[current_day+1]){
                    state=1;
                    buy_price=prices[current_day];
                    current_day+=1;
                }else{
                    current_day+=1;
                }
            }else{
                if(prices[current_day]>prices[current_day+1]){
                    state=0;
                    current_earn = current_earn + prices[current_day]-buy_price;
                    current_day+=1;
                }else{
                    current_day+=1;
                }
            }

        }
        if(state==1){
            current_earn = current_earn + prices[prices.size()-1]-buy_price;
        }
        return current_earn;
    }
};