class Solution {
public:
    using pi = pair<int,int>;
    using pii = pair<int,pair<int,int>>;
    
    int minTimeToReach(vector<vector<int>>&v) {
        int n = v.size();
        int m = v[0].size();
        
        priority_queue<pii,vector<pii>,greater<pii>>minh;
        
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        int dx[4]={0,-1,1,0};
        int dy[4]={-1,0,0,1};
        minh.push({0,{0,0}});
        vis[0][0] = 1;
        vector<vector<int>>time(n,vector<int>(m,INT_MAX));
        while(!minh.empty()){
            auto p = minh.top();
            minh.pop();
            int t = p.first;
            auto node = p.second;
            int x = node.first;
            int y = node.second;
            if(x==n-1 && y == m-1){
                return t;
            }
            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m &&!vis[nx][ny]){
                    int nt = min(time[nx][ny],(t+1+((t<v[nx][ny])?abs(t-v[nx][ny]):0)));
                    minh.push({nt,{nx,ny}});
                    vis[nx][ny] = 1; 
                }
            }
        }
        return 0;
    }
};