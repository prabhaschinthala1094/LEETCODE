class Solution {
public:
    int solve(int ind,vector<int>&nums,vector<int>&dp){
        if(ind>=nums.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        return dp[ind]=max(nums[ind]+solve(ind+2,nums,dp),solve(ind+1,nums,dp));
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
       return solve(0,nums,dp);
    }
};