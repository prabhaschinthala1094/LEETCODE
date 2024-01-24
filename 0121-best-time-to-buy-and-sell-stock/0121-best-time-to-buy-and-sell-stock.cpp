class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>pre(n),suf(n);
        pre[0]=prices[0];
        suf[n-1]=prices[n-1];
        for(int i=1;i<n;i++)pre[i]=min(pre[i-1],prices[i]);
        for(int i=n-2;i>=0;i--)suf[i]=max(suf[i+1],prices[i]);
        int ans=0;
        for(int i=0;i<n;i++)ans=max(ans,abs(pre[i]-suf[i]));
        return ans;
    }
};