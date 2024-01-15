class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int>st;
        for(auto it: matches){
            st.insert(it[0]);
            st.insert(it[1]);
        }
        map<int,int>mp;
        for(auto it:matches){
            mp[it[1]]++;
        }
        vector<vector<int>>ans(2);
        for(auto it:mp){
            if(it.second==1){
                ans[1].push_back(it.first);
            }
        }
        for(auto it:st){
            if(mp.find(it)==mp.end()){
                ans[0].push_back(it);
            }
        }
        for(auto &it:ans){
            sort(it.begin(),it.end());
        }
        return ans;
    }
};