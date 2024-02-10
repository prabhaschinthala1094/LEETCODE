class Solution {
public:
using ll = long long;
    int reverse(int x) {
        ll sign=1;
        if(x<0)sign=-1;
        x=abs(x);
        ll ans=0;
        while(x) {
            ll r = (ll)x%10;
            ans= ans*10 + r;
            x/=10;
        }
        if(ans>INT_MAX)return 0;
        return (int)(sign*ans);
    }
};