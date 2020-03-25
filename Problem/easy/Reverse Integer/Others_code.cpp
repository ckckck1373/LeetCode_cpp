/*
    3/26/2020.
    Other's code
    100% faster 99.8% better space
*/

int reverse(int x) {
        long long int ans=0;
        while(x!=0)
        {
            ans=(ans*10) +(x%10); // ans gradually grows, so as long as it exceed the limit it should return 0 
            x/=10;
            if(ans> INT_MAX)
                return 0;
            if(ans<INT_MIN)
                return 0;
        }
        return ans;
    }