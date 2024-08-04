class Solution {
public:
    int mod = 1000000007;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        vector<int>v = nums;
      
        for(int i=0;i<n;i++){
             int s = nums[i];
            for(int j=i+1;j<n;j++){
                s+=(nums[j])%mod;
                v.push_back(s%mod);
            }
        }
        
        sort(v.begin(),v.end());
        
        int ans = 0;
        for(int i=left-1;i<right;i++){
            ans = (ans%mod + v[i]%mod)%mod;
        }
        return ans%mod;
        
    }
};