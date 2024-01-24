class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxi=0;
        int minibuy=prices[0];
        for(int i=1;i<n;i++){
            int curr=prices[i]-minibuy ;
            maxi=max(maxi,curr);
            minibuy=min(minibuy,prices[i]);
        }
        return maxi;
    }
};