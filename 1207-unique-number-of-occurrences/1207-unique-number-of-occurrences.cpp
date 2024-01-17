class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        unordered_set<int>s;
        for(auto it:arr){
            mp[it]++;
        }
        for(auto it:mp){
            if(s.find(it.second)!=s.end()){
                return 0;
            }
            s.insert(it.second);
        }
        return 1;
    }
};