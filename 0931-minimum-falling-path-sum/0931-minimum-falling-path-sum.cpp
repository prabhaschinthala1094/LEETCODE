class Solution {
public:
    
//     int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>&dp) {
//         if(j<0 || j>=matrix.size())return 1e9;
//         if(i>=matrix.size())return 0;
//         if(dp[i][j]!=-1)return dp[i][j];
//         int l=INT_MAX,r=INT_MAX,d=INT_MAX;
        
//         l=min(l,matrix[i][j]+solve(i+1,j-1,matrix,dp));
//         r=min(r,matrix[i][j]+solve(i+1,j+1,matrix,dp));
//         d=min(d,matrix[i][j]+solve(i+1,j,matrix,dp));
        
//         return dp[i][j]=min(l,min(d,r));
        
//     }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        // int ans=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++)dp[0][j]=matrix[0][j];
        
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                 int l=matrix[i][j];
                if(j-1>=0)l+=dp[i-1][j-1];
                else l+=1e9;
                 int r=matrix[i][j];
                if(j+1<n)r+=dp[i-1][j+1];
                else r+=1e9;
                 int d=matrix[i][j]+dp[i-1][j];
                dp[i][j]=min(l,min(r,d));
            }
        }
        
       int mini=INT_MAX;
        for(int j=0;j<n;j++){
            mini=min(mini,dp[n-1][j]);
        }
        return mini;
        
    }
};