class Solution {
public:
using ll=long long;
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        vector<unordered_map<ll,int>>dp(n);
        int ans=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                ll diff=(ll)nums[i]-(ll)nums[j];
                dp[i][diff]+=dp[j][diff]+1;
                ans+=dp[j][diff];
            }
            
        }
        return ans;
        
    }
};