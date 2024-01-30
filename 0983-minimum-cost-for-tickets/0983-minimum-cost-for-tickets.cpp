class Solution {
public:
    int nextInd(int i,vector<int>&days) {
        int ans=lower_bound(days.begin(),days.end(),i)-days.begin();
        return ans;
    }
    int solve(int ind,vector<int>& days, vector<int>& costs,vector<int>&dp) {
        if(ind>=days.size()) return 0;
        if(ind==days.size()-1) return min(costs[0],min(costs[1],costs[2]));
        if(dp[ind]!=-1)return dp[ind];
        
        int one = costs[0]+solve(ind+1,days,costs,dp);
        int WInd= nextInd(days[ind]+7,days);
        int MInd= nextInd(days[ind]+30,days);
        
        int weekly = costs[1]+solve(WInd,days,costs,dp);
        int monthly = costs[2]+solve(MInd,days,costs,dp);
        return dp[ind] = min(one,min(weekly,monthly));
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n+1,-1);
        return solve(0,days,costs,dp);
    }
};