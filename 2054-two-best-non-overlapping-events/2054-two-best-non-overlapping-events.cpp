class Solution {
public:
    int func(int i,vector<vector<int>>& events){
        int n = events.size();
        int s = 0;
        int e = n-1;
        while(s<=e){
            int mid = (s+e)/2;
            if(events[i][1]<events[mid][0]){
                e = mid -1;
            }
            else{
                s = mid + 1;
            }
        }
        return s;
        
    }
    int solve(int i,vector<vector<int>>& events,int cnt,vector<vector<int>>&dp){
        if(cnt == 2)return 0 ;
        if(i>=events.size())return 0;
        if(dp[i][cnt]!= -1 )return dp[i][cnt];
        int valid = func(i,events);
        int take = events[i][2]+solve(valid,events,cnt+1,dp);
        int nottake = solve(i+1,events,cnt,dp);
        return dp[i][cnt] = max(take,nottake);
    }
   
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        
        sort(events.begin(),events.end());
        vector<vector<int>>dp(n+1,vector<int>(3,-1));
        int ans = solve(0,events,0,dp);
        return ans;
    }
};