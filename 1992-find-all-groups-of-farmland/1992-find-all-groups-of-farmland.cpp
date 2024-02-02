class Solution {
public:
    
    void dfs(int i,int j,vector<vector<int>>& land,vector<vector<bool>>&vis,int &r1,int &c1,int &r2,int &c2,vector<int>&drow,vector<int>&dcol) { 
    
        r1=min(r1,i);c1=min(c1,j);r2=max(r2,i);c2=max(c2,j);
        vis[i][j]=1;
        for(int k=0;k<4;k++) {
            int nrow=drow[k]+i;
            int ncol=dcol[k]+j;
            if(nrow>=0 && nrow<land.size() && ncol>=0 && ncol<land[0].size() && land[nrow][ncol]==1 && !vis[nrow][ncol]){
                dfs(nrow,ncol,land,vis,r1,c1,r2,c2,drow,dcol);
            }
        }
        return;
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size();
        int m=land[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        vector<vector<int>>ans;
        vector<int>drow={0,-1,1,0};
        vector<int>dcol={-1,0,0,1};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){ 
                if(!vis[i][j] && land[i][j]==1){
                    int r1=INT_MAX;
                    int c1=INT_MAX;
                    int r2=INT_MIN;
                    int c2=INT_MIN;
                    dfs(i,j,land,vis,r1,c1,r2,c2,drow,dcol);
                    ans.push_back({r1,c1,r2,c2});
                }
            }
        }
        return ans;
    }
};