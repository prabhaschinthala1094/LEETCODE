class Solution {
public:
    int maxSatisfied(vector<int>& cust, vector<int>& grumpy, int minutes) {
        int n = cust.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
                ans+=cust[i];
                cust[i] = 0;
            }
        }
        int maxi = 0;
        int sum = 0;
        for(int i=0;i<n;i++){
            if(i<minutes){
                sum+=cust[i];
            }
            else{
                maxi = max(sum,maxi);
                sum+=cust[i];
                sum-=cust[i-minutes];
            }
        }
        maxi = max(sum,maxi);
        
        return maxi+ans;
    
    }
};