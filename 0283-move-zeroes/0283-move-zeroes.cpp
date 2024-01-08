class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,n=nums.size(),j=0;
        for(;i<n;i++){
            if(nums[i]!=0){
                nums[j++]=nums[i];
            }
        }
        for(;j<n;j++)nums[j]=0;
    }
    
};