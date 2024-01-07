class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3)return 0;
        int prev_diff=nums[1]-nums[0];
        int ans=0,cnt=0,diff;
        for(int i=1;i<n-1;i++){
            diff=nums[i+1]-nums[i];
            if(prev_diff==diff){
                cnt++;
            }
            else{
                cnt=0;
                prev_diff=diff;
            }
            ans+=cnt;
        }
        return ans;
        
    }
};