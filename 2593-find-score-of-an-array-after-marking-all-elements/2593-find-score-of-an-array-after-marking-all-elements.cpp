class Solution {
public:
    using pi = pair<int,int>;
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        priority_queue<pi,vector<pi>,greater<pi>>minh;
        for(int i=0;i<n;i++)minh.push({nums[i],i});
        vector<bool>vis(n,0);
        long long ans = 0;
        while(!minh.empty()){
            auto [val,ind] = minh.top();
            minh.pop();
            if(!vis[ind]){
                ans += val;
                vis[ind] = 1;
                if(ind>0)vis[ind-1]= 1;
                if(ind<n-1)vis[ind+1]=1;
            }
        }
        return ans;
    }
};