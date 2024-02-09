class Solution {
public:
    int dp[2501][2502];
    int solve(int ind,int prev,vector<int>&nums) {
        if(ind>=nums.size())return 0;
        if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];
        if(prev==-1 || nums[prev]<nums[ind]) {
            return dp[ind][prev+1]=max(1+solve(ind+1,ind,nums),solve(ind+1,prev,nums));
        } 
        else{
            return dp[ind][prev+1] = solve(ind+1,prev,nums);
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,nums);
    }
};