class Solution {
public:
    int dp[1001][1001];
    bool check(string &s,int i,int j) {
        if(i>j)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==s[j])return dp[i][j]=check(s,i+1,j-1);
        return dp[i][j]=0;
    }
    
    int countSubstrings(string s) {
        memset(dp,-1,sizeof(dp));
        int n=s.size();
        int cnt=0;
        
        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                if(check(s,i,j) == true) {
                    cnt++;
                }
            }
        }
        
        return cnt; 
        
    }
};