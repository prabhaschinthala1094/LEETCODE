class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size(),low=INT_MAX,high=INT_MAX;
        if(n<3)return 0;
        for(int i=0;i<n;i++){ 
            if(nums[i]>high)return 1;
            else if(nums[i]<low)low=nums[i];
            else if (nums[i]>low && nums[i]<high)high=nums[i];
        }
        return 0;
    }
};