class Solution {
public:
    int ans=0;
    void solve(int n,vector<int>&t){
        for(int i=2;i*i<n;i++){
            if(t[i]==1){                
               for(int j=2*i;j<n;j+=i){
                   t[j]=0;
               }
            }
        }
        for(auto it:t){
            if(it==1)ans++;
        }
        
    }
    int countPrimes(int n) {
        vector<int>t(n,1);
        if(n==0||n==1)return 0;
        // for(int i=0;i<n+1;i++)cout<<t[i]<<endl;
        t[1]=t[0]=0;
        solve(n,t);
        return ans;
    }
};