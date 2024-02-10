class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return 0;
        if(x==0)return 1;
        long long a=0,k=(long long)x;
        while(x){
            a*=10;
            a+=(long long)x%10;
            x/=10;
        }
        // cout<<a<<endl;
        return (k==a);
    }
};