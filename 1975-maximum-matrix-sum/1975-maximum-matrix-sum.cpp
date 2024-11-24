class Solution {
public:
using ll = long long; 
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        ll mini = LONG_MAX;
        int neg =0;
        ll sum = 0;
        for(auto i:matrix){
            for(auto j:i){
                sum+=abs(j);
                mini = min(mini,(ll)abs(j));
                if(j<=0){
                    neg++;
                }
            }
        }
        return ((neg&1)?(sum-2*mini):sum);
        
    }
};