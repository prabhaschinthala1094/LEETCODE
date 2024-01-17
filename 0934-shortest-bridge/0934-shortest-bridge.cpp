class Solution {
public:
using pii=pair<int,int>;
    queue<pii>q;
    bool valid(int i,int j,vector<vector<int>>& grid){
        return (i>=0 && j>=0 && i<grid.size() && j<grid.size() );
    }
    void dfs(int i,int j,vector<vector<bool>>&vis,vector<vector<int>>& grid){
        vis[i][j]=1;
        grid[i][j]=2;
        q.push({i,j});
        int drow[4]={0,-1,1,0};
        int dcol[4]={-1,0,0,1};
        for(int k=0;k<4;k++){
            int nrow=i+drow[k];
            int ncol=j+dcol[k];
            if( nrow>=0 && nrow<grid.size() && ncol>=0&& ncol<grid[0].size()  &&grid[nrow][ncol]==1 && !vis[nrow][ncol]){  
                dfs(nrow,ncol,vis,grid);
            }
        }
        return ;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<bool>>vis(n,vector<bool>(n,0));
        bool found1=0;
        for(int i=0;i<n && !found1;i++){
            for(int j=0;j<n && !found1;j++){
                if(grid[i][j]==1 && vis[i][j] == 0){
                    dfs(i,j,vis,grid);
                    found1=1;
                }
            }
        }
       int ans=0;
          while(!q.empty()){
            int currSize=q.size();
            for(int i =0;i<currSize;i++){
                auto ele=q.front();q.pop();
                int r=ele.first; int c=ele.second;
                vis[r][c]=1;
                //up
                if (valid(r-1, c, grid) && !vis[r-1][c]) {
                    if (grid[r-1][c] == 1) return ans;
                    else if (grid[r-1][c] == 0) {
                        vis[r-1][c]=1;
                        q.push(make_pair(r-1, c));
                    }
                }
                //down
                if (valid(r+1, c, grid) && !vis[r+1][c]) {
                    if (grid[r+1][c] == 1) return ans;
                    else if (grid[r+1][c] == 0) {
                        q.push(make_pair(r+1, c));
                        vis[r+1][c]=1;
                    }
                }
                //left
                if (valid(r, c-1, grid) && !vis[r][c-1]) {
                    if (grid[r][c-1] == 1) return ans;
                    else if (grid[r][c-1] == 0) {
                        q.push(make_pair(r, c-1));
                        vis[r][c-1]=1;
                    }
                }
                //right
                if (valid(r, c+1, grid) && !vis[r][c+1]) {
                    if (grid[r][c+1] == 1) return ans;
                    else if (grid[r][c+1] == 0) {
                        q.push(make_pair(r, c+1));
                        vis[r][c+1]=1;
                    }
                }
            }
            ans++;
        }
        return ans;
    }
    
};