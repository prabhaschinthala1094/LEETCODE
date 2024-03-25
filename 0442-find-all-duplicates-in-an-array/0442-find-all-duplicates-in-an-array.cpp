class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto it:nums)mp[it]++;
        vector<int>ans;
        for(auto it:mp){
            if(it.second != 1){
                ans.push_back(it.first);
            }
        }
        sort(begin(ans),end(ans));
        return ans;
    }
};