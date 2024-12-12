class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>vix(n,0);
        for(int i=1;i<n;i++){
            if(nums[i]%2 == nums[i-1]%2){
                
                vix[i] = vix[i-1]+1;
            }
            else{
                vix[i] = vix[i-1];
            }
        }
        // for(auto i:vix)cout<<i<<" ";
        // cout<<endl;
        int m = queries.size();
        vector<bool>ans(m,0);
        for(int i=0;i<m;i++){
            if(vix[queries[i][1]] - vix[queries[i][0]] == 0)ans[i] = true;
        }
        return ans;
    }
};