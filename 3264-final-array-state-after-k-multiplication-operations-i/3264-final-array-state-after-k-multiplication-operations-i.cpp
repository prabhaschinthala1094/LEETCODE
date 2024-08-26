class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        while(k--){
            int ind = 0;
            int val = INT_MAX;
            for(int i=0;i<n;i++){
                if(nums[i]<val){
                    val = nums[i];
                    ind = i;
                }
            }
            nums[ind] *= multiplier;  
        }
        return nums;
    }
};