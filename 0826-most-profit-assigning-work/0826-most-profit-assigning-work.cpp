class Solution {
public:
using pii=pair<int,int>;
    int maxProfitAssignment(vector<int>& diff, vector<int>& prof, vector<int>& work) {
        int n = diff.size();
        int m = work.size();
        vector<pii>nums;
        for(int i=0;i<n;i++){
            nums.push_back({prof[i],diff[i]});
        }
        sort(nums.rbegin(),nums.rend());
        sort(work.rbegin(),work.rend());
        int ans = 0;
        int j = 0;
        for(int i=0;i<m;i++){
            int cur = work[i];
            while(j<n&&cur<nums[j].second)j++;
            if(j==n)break;
            ans += nums[j].first;
        }
        return ans;
    }
};