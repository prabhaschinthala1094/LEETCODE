class Solution {
public:
    unordered_map<int,vector<int>>mp;
    void dfs(int node,vector<bool>&vis){
        vis[node]=1;
        for(auto &it:mp[node]){
            if(!vis[it]){
                dfs(it,vis);
            }
        }
        return ;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(isConnected[i][j]==1 && i!=j){
                   mp[i+1].push_back(j+1);
               }
           }    
        }
        
        vector<bool>vis(n+1,0);
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,vis);
            }
        }
        return cnt;
    }
};