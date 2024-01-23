class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n),suf(n);
        pre[0]=nums[0];
        suf[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            pre[i]=min(pre[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            suf[i]=min(suf[i+1],nums[i]);
        }
        int sum=INT_MAX;
        for(int i=1;i<n-1;i++){
            if(nums[i]>pre[i-1] &&nums[i]>suf[i+1])
            sum=min(pre[i-1]+suf[i+1]+nums[i],sum);
        }
        return (sum!=INT_MAX)?sum:-1;
    }
};