class Solution {
public:
   
    int dp[51][51][51];
     int mod=1e9+7;
    int solve(int row,int col,int k,int moves,int m,int n,vector<int>&drow,vector<int>&dcol){
        if(row<0 ||row>=m || col<0 || col>=n){
            return 1;
        }
        if(k==moves){
            return 0;
        }
        if(dp[row][col][k]!=-1)return dp[row][col][k];
        int ans=0;
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            ans= ((ans)%mod+(solve(nrow,ncol,k+1,moves,m,n,drow,dcol))%mod)%mod;
        }
        return dp[row][col][k]=(ans)%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        vector<int>drow={0,-1,1,0};
        vector<int>dcol={-1,0,0,1};
        return solve(startRow,startColumn,0,maxMove,m,n,drow,dcol);
    }   
};