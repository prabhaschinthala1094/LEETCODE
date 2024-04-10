class Solution {
public:
    using ll = long long;
    int mod = 1e9+7;
    
    ll gcd(ll a , ll b) {
        if(b ==0 )return a;
        return gcd(b,a%b);
    }
    
    ll lcm(int a ,int b) {
        return ((ll)a*(ll)b)/gcd((ll)a,(ll)b);
    }
    
    bool possible(ll mid,int n, int a, int b) {
        ll cnt = 0;
        ll val = lcm(a,b);
        cnt += (mid/(ll)a);
        cnt += (mid/(ll)b);
        cnt -= (mid/(ll)val);
        return ((n)<=cnt);
        
    }
    int nthMagicalNumber(int n, int a, int b) {
        ll s = 0;
        ll e = LONG_MAX;
        while(s<=e){
            ll mid = s+(e-s)/2;
            if(possible(mid,n,a,b)){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return s%mod;
    }
};