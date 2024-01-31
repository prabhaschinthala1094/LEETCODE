class Solution {
public:
    int dp[101][101];
    bool solve(int i,int j,int k,string &s1, string &s2, string &s3) {
       if(i>s1.size() || j>s2.size())return 0;
        if(i==s1.size() && j==s2.size()){
            if(k==s3.size())return 1;
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        bool ans=0;
        if(s3[k]==s2[j] && s3[k]==s1[i]){
            ans=(ans|solve(i+1,j,k+1,s1,s2,s3)) | solve(i,j+1,k+1,s1,s2,s3);
        }
        else if(s3[k]==s1[i]){
            ans=ans | solve(i+1,j,k+1,s1,s2,s3);
        }
        else if(s3[k]==s2[j]){
            ans=ans | solve(i,j+1,k+1,s1,s2,s3);
        }
        else return dp[i][j]=0;
        
        return dp[i][j]=ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        // if(s1.size()==0 && s2.size()==0){
        //     if(s3.size()==0)return 1;
        //     return 0;
        // }
        memset(dp,-1,sizeof(dp));
        // cout<<dp[21][21][31];
       return solve(0,0,0,s1,s2,s3);
    }
};