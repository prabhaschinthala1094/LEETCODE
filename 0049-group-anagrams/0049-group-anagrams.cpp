class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string>v=strs;
        for(int i=0;i<strs.size();i++){
            sort(v[i].begin(),v[i].end());
        }
        map<string,vector<int>>mp;
        for(int i=0;i<strs.size();i++){
            mp[v[i]].push_back(i);
        }
        vector<vector<string>>ans;
        
        for(auto inds:mp){
            vector<string>v;
            for(auto it:inds.second){
                v.push_back(strs[it]);
            }
            ans.push_back(v);
        }
        return ans;
        
    }
};