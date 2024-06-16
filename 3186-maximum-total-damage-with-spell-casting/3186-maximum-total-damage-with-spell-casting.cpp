class Solution {
public:
    using ll = long long int;
    
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(), power.end());
        int n = power.size();
        vector<ll> dp(n+1, 0); // Initialize dp array with 0 instead of -1 for tabulation
        map<int, int> mp;
        for (auto i : power) mp[i]++;
        power.clear();
        for (auto i : mp) power.push_back(i.first);
        
        // Start filling dp from the end towards the beginning
        for (int i = power.size() - 1; i >= 0; --i) {
            int ind = upper_bound(power.begin(), power.end(), power[i] + 2) - power.begin();
            ll take = (ll)mp[power[i]] * (ll)power[i] + (ind < power.size() ? dp[ind] : 0);
            ll nottake = (i + 1 < power.size() ? dp[i + 1] : 0);
            dp[i] = max(take, nottake);
        }
        
        return dp[0]; // The result is stored in dp[0]
    }
};
