class Solution {
public:
    int mod = 1e9+7;
    int dp[1001][1001];
    int solve(int n,int k) {
        if( k==0)return 1;
        if(n==0)return 0;
        if(dp[n][k]!=-1)return dp[n][k];
        int ans=0;
        for(int i=0;i<n&&i<=k;i++){
            ans = (ans%mod + solve(n-1,k-i)%mod)%mod;
        }
        return dp[n][k]=(ans)%mod;
    }
    int kInversePairs(int n, int k) {
        if(k==0)return 1;
        memset(dp,-1,sizeof(dp));
        // cout<<dp[239][413]<<endl;
       return solve(n,k)%mod;
    }
};