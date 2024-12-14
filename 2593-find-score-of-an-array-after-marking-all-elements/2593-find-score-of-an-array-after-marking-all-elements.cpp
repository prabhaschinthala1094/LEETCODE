class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)v.push_back({nums[i],i});
        sort(v.begin(),v.end());
        vector<bool>vis(n,0);
        long long ans = 0;
        for(int i=0;i<n;i++){
            int ind = v[i].second;
            if(!vis[ind]){
                ans += v[i].first;
                vis[ind] = 1;
                if(ind>0)vis[ind-1]= 1;
                if(ind<n-1)vis[ind+1]=1;
            }
        }
        return ans;
    }
};