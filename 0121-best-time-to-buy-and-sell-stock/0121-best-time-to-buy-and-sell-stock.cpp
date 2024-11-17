class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>f(n,0),b(n,0);
        f[0]=prices[0];
        b[n-1]= prices[n-1];
        for(int i=1;i<n;i++) {
            f[i] = min(f[i-1],prices[i]);
        }
        for(int i = n-2;i>=0;i--){
            b[i] = max(b[i+1],prices[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,b[i]-f[i]);
        }
        return ans;
    }
};