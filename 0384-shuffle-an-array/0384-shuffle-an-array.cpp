class Solution {
public:
    vector<int>v,p;
    Solution(vector<int>& nums) {
        for(auto it:nums){
            v.push_back(it);
            p.push_back(it);
        }
    }
    
    vector<int> reset() {
       return p=v;
    }
    
    vector<int> shuffle() {
       random_shuffle(p.begin(),p.end());
        return p;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */