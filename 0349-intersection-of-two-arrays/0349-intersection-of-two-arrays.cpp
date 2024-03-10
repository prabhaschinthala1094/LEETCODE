class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>s,q;
        for(auto it:nums1)s.insert(it);
        vector<int>ans;
        for(auto it:nums2){
            if(s.find(it)!=s.end()){
                q.insert(it);
            }
        }
        for(auto it:q)ans.push_back(it);
        return ans;
    }
};