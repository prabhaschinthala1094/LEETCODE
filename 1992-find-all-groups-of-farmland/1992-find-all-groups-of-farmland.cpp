class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size();
        int m=land[0].size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j]==1){
                    
                    int r=i;
                    int c=j;
                    
                    while(r<n && land[r][j]==1){
                        r++;
                    }
                    r--;
                    
                    while(c<m && land[r][c]==1){
                        c++;
                    }
                    
                    c--;
                    
                    ans.push_back({i,j,r,c});
                    
                    for(int a=i;a<=r;a++){
                        for(int b=j;b<=c;b++){
                            land[a][b]=0;
                        }
                    }
                    
                    
                }
            }
        }
        return ans;
    }
};