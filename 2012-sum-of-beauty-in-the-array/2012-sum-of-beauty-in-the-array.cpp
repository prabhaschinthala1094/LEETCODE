class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n),suf(n);
        pre[0]=nums[0];
        suf[n-1]=nums[n-1];
        for(int i=1;i<n;i++)pre[i]=max(pre[i-1],nums[i]);
        for(int i=n-2;i>=0;i--)suf[i]=min(suf[i+1],nums[i]);
        
        int sum=0;
    
        for(int i=1;i<=n-2;i++){
            if(pre[i-1]<nums[i] && suf[i+1]>nums[i]){
                sum+=2;
            }
            else if(nums[i - 1] < nums[i]  && nums[i]< nums[i + 1]){
                // cout<<i<<' ';
                sum+=1;
            }
          
        }
        return sum;
        
        
    }
};