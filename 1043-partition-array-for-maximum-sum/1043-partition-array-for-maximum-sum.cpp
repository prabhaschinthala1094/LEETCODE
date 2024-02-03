class Solution {
public:
    int dp[501];
    int solve(int ind,vector<int>&arr,int k) {
        if(ind>=arr.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        int maxi=0,sum=0;
        
        for(int i=ind;i<min((int)arr.size(),ind+k) ;i++) {
            maxi=max(maxi,arr[i]);
            sum=max(sum,(i-ind+1)*maxi+solve(i+1,arr,k));
        }
        return dp[ind]=sum;
        
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        int n=arr.size();
        return solve(0,arr,k);
    }
};