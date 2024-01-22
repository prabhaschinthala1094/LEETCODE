class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
       unordered_set<int>s;
        vector<int>ans(2,0);
        for(auto it:nums){
            if(s.find(it)!=s.end()){
                ans[0]=it;
            }
            s.insert(it);
        }
        for(int i=1;i<=nums.size();i++){
            if(s.find(i)==s.end()){
                ans[1]=i;
                break;
            }
        }
        return ans;
    }
};