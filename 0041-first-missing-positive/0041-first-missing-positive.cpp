class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,bool>mp;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                mp[nums[i]]=1;
            }
            
        }
        // for(auto it:mp){
        //     cout<<it.first<<"->"<<it.second<<endl;
        // }
        int k=mp.size();
        int ans=1;
        bool p=0;
        for(int i=1;i<=k;i++){
            if(mp[i]==0){
                ans=i;
                p=1;
                break;
            }
        }
        if(p==0)ans=k+1;
        return ans;

    }
};