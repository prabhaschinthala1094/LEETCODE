class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        map<int,int>mp;
        for(auto it:nums)mp[it]++;
        for(auto it:mp){
            if(it.second==1)return -1;
            ans += ceil((double)(it.second) / 3);
        }
        return ans;
    }
};