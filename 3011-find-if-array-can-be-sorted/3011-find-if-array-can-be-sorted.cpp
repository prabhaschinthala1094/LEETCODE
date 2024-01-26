class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>bits(n,0);
        for(int i=0;i<n;i++)bits[i]=__builtin_popcount(nums[i]);
        int i=1;
        int maxi=nums[0];
        int mini=nums[0];
        vector<pair<int,int>>mp;
        for(;i<n;i++){
            if(bits[i]!=bits[i-1]){
                mp.push_back({mini,maxi});
                mini=INT_MAX;
                maxi=INT_MIN;
            }
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
        }
        mp.push_back({mini,maxi});
        int p=0;
        for(auto it:mp)cout<<it.first<<" "<<it.second<<endl;
        for(auto it:mp){
            int u=it.first;
            int v=it.second;
            if(p>u){
                return 0;
            }
            p=v;
        }
        
        return 1;
    }
};