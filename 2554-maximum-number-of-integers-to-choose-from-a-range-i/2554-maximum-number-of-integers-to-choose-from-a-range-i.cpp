class Solution {
public:
    using ll = long long int;
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int,int>mp;
        for(auto i:banned)mp[i]++;
        ll sum = 0;
        int k = 0;
        for(int i=1;i<=n;i++){
            if(mp.find(i)==mp.end()){
                sum+=i;
                k++;
                if(sum>maxSum){
                    return --k;
                }
            }
        }
        return k;
    }
};