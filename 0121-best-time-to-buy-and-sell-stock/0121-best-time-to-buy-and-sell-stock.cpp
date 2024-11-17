class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int cur_prof = 0;
        int mini= prices[0];
        int profit = 0;
        for(int i=0;i<n;i++){
            cur_prof = prices[i] - mini;
            mini = min(mini,prices[i]);
            profit = max(profit,cur_prof); 
        }
        return profit;
    }
};