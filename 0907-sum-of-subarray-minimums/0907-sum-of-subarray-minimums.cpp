class Solution {
public:
    int MOD=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>left(n,-1),right(n,n);

        stack<int>s;

        for(int i=0;i<n;i++){
            while(s.size()&& arr[i]<arr[s.top()])s.pop();
            if(s.size())left[i]= i - s.top();
            else left[i]=i+1;
            s.push(i);
        }
        // for(auto it:left)cout<<it<<" ";
        while(!s.empty())s.pop();
        // cout<<"\n";
        for(int i=n-1;i>=0;i--){
            while(s.size()&& arr[i]<=arr[s.top()])s.pop();
            if(s.size())right[i]= s.top() - i;
            else right[i]=n-i;
            s.push(i);
        }
        // for(auto it:right)cout<<it<<" ";
           int res = 0;
        for(int i=0; i<n; i++)
        {
            long long prod = (left[i]*right[i])%MOD;
            prod = (prod*arr[i])%MOD;
            res = (res + prod)%MOD;
        }
        
        return res%MOD;
        

    }
};