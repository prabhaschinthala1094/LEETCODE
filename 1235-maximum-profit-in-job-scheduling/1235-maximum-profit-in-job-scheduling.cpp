class Solution {
public:
using pii= pair<pair<int,int>,int>;

    int solve(int ind,vector<pii>&mp,vector<int>& startTime,vector<int>&dp){
        if(ind==startTime.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        int next=lower_bound(startTime.begin(),startTime.end(),mp[ind].first.second)-startTime.begin();
        return dp[ind]=max(mp[ind].second+solve(next,mp,startTime,dp),solve(ind+1,mp,startTime,dp));
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<pii>mp(n);
        for(int i=0;i<n;i++)mp[i]={{startTime[i],endTime[i]},profit[i]};
        sort(mp.begin(),mp.end());
        for(int i=0;i<n;i++)startTime[i]=mp[i].first.first;
        vector<int>dp(n+1,-1);
        return solve(0,mp,startTime,dp);
    }
};