class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int maxi=0;
        int sum=0;
        for(int i=0,j=0;j<n;j++){
            if(mp[nums[j]]>0){
               while(i<max(mp[nums[j]],i)){
                   sum-=nums[i];
                   i++;
               }
            }
            sum+=nums[j];
            maxi=max(sum,maxi);
            mp[nums[j]]=j+1;
        }
        return maxi;
    }
};