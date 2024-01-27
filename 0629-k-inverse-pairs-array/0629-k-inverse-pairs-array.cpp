class Solution {
public:
    int mod = 1e9+7;
    
    // int solve(int n,int k) {
    //     if( k==0)return 1;
    //     if(n==0)return 0;
    //     if(dp[n][k]!=-1)return dp[n][k];
    //     int ans=0;
    //     for(int i=0;i<n&&i<=k;i++){
    //         ans = (ans%mod + solve(n-1,k-i)%mod)%mod;
    //     }
    //     return dp[n][k]=(ans)%mod;
    // }
    int kInversePairs(int n, int k) {
        if(k==0)return 1;
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                if(j==0){
                    dp[i][j]=1;
                    continue;
                }
                for(int p=0;p<i && p<=j;p++){
                    dp[i][j]=(dp[i][j]%mod+dp[i-1][j-p]%mod)%mod;
                }
            }
        }
       
        return dp[n][k];
    }
};