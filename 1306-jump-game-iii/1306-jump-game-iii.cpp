class Solution {
public:
    bool solve(int ind,vector<int>&arr,vector<int>&vis,vector<int>&dp){
        if(ind>arr.size()-1 || ind<0 || vis[ind])return 0;
        if(arr[ind]==0)return 1;
        if(dp[ind]!=-1)return dp[ind];
        vis[ind]=1;
        bool lh=solve(ind-arr[ind],arr,vis,dp);
        vis[ind]=0;
        bool rh=solve(ind+arr[ind],arr,vis,dp);
        return dp[ind]=rh|lh;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int>vis(arr.size(),0);
        vector<int>dp(arr.size(),-1);
        return solve(start,arr,vis,dp);
    }
};