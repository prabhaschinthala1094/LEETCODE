class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        multiset<int>s;
        long long ans = 0;
        int j = 0;
        int i = 0;
        while(j<n){
    
            s.insert(nums[j]);
            while(s.size()>1&&*s.rbegin()-*s.begin() > 2){
                 s.erase(s.find(nums[i]));
                 i++;
             }
              ans += (j-i+1);
                j++;     
         }   
        return ans;
        
    }
};