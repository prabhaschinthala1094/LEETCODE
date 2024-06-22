class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int num = 0;
        int cnt = 0;
        int j=0;
       for(int i=0;i<n;i++){
           if(nums[i]&1){
               k--;
               cnt =0;
           }
           while(k==0){
               k+=(nums[j++]&1);
               ++cnt;
           }
           num+=cnt;
       }
        return num;
    }
};