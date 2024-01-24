class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int maxi=nums[0];
        for(int i=0,j=0;j<n;j++){
            if(mp[nums[j]]>0){
                i=max(mp[nums[j]],i);
            }
            int sum=accumulate(nums.begin()+i,nums.begin()+j+1,0);
            maxi=max(maxi,sum);
            mp[nums[j]]=j+1;
        }
        return maxi;
    }
};