class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix=1,postfix=1,n=nums.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=prefix;
            if(i<n-1)prefix*=nums[i];
        }
        for(int i=n-1;i>=0;i--){
            ans[i]*=postfix;
            if(i>0)postfix*=nums[i];
        }
        return ans;
        
    }
};