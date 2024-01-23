class Solution {
public:
    using ll=long long;
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n),suf(n);
        pre[0]=nums[0];
        suf[n-1]=nums[n-1];
        for(int i=1;i<n-2;i++){  
            pre[i]=max(pre[i-1],nums[i]);
        }
        for(int i=n-2;i>=2;i--){
            suf[i]=max(suf[i+1],nums[i]);
        }
        ll ans=0;
        for(int i=1;i<n-1;i++){
            ans=max(ans,(ll)(pre[i-1]-nums[i])*suf[i+1]);
        }
        return max(0LL,ans);
        
    }
};