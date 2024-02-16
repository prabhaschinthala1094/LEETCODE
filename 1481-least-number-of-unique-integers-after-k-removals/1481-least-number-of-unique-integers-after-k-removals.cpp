class Solution {
public:
    // static bool cmp(pair<int,int>&a,pair<int,int>&b){
    //     return (a.second<=b.second);
    // }
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(auto it:arr)mp[it]++;
        
        vector<pair<int,int>>dp;
        
        for(auto it:mp){
            dp.push_back(it);
        }

        sort(begin(dp),end(dp),[](auto a,auto b){
            return a.second<b.second;
        });
        // sort(mp.begin(),mp.end(),cmp);
        int sz=dp.size();
        int m=0;
        for(auto it:dp) {
            if(k<it.second)return sz-m;
            k-=it.second;
            m++;
        }
        return 0;
    }
};