class Solution {
public:
    int smallestNumber(int n, int t) {
        for(; n;++n){
            int num = n;
            int prod = 1;
            while(num){
                prod *= (num%10);
                num/=10;
            }
            if(prod % t == 0)return n;
        }
        return 0;
    }
};