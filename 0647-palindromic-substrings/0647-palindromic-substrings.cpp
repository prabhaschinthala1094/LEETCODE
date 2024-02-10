class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        int cnt=0;
        vector<vector<bool>>dp(n+1,vector<bool>(n+1,0));
        for(int L=1;L<=n;L++) {
            for(int i=0;i+L-1<n;i++) {
                int j= i+L-1;
                if(i==j)dp[i][j]=1;
                else if(i+1 == j){
                    dp[i][j] = (s[i] == s[j]);
                }
                else{
                    dp[i][j]= (s[i]==s[j] && dp[i+1][j-1]==1);
                }
                if(dp[i][j] == 1)cnt++;
            }
        }
        return cnt;
    }
};