class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int size = cardPoints.size();
        int sum=0;
        int sum_back=0;
        int result;
        for(auto& u: cardPoints){
            sum += u;
        }
        if(k>=size)return sum;
        
        
    
        for(int i=0;i<k;i++){
            sum_back += cardPoints[size-i-1];
        }
        int temp=sum_back;
        //cout << sum_back;
        result = sum_back;
        for(int i=0;i<k;i++){
            temp = temp - cardPoints[size-k+i];
            temp = temp + cardPoints[i];
            //cout << "temp: " << temp << endl;
            if(result<temp) result=temp;
        }
        return result;
    }
};_