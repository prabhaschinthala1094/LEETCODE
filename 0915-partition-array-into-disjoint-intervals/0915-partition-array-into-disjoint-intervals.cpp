class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n),suf(n);
        pre[0]=nums[0];
        suf[n-1]=nums[n-1];
        for(int i=1;i<n;i++)pre[i]=max(pre[i-1],nums[i]);
        for(int i=n-2;i>=0;i--)suf[i]=min(suf[i+1],nums[i]);
        int ans=1;
        for(int i=0;i<n-1;i++){
            if(pre[i]<=suf[i+1])return i+1;
        }
        return ans;
    }
};