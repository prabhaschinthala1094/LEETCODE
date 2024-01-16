class Solution {
public:
    void seive(vector<bool>&isPrime,int right){
        isPrime[0]=isPrime[1]=0;
        for(int i=2;i*i<=right;i++){
            if(isPrime[i]==1){
                for(int j=2*i;j<=right;j+=i){
                    isPrime[j]=0;
                }
            }
        }
    }
    vector<int> closestPrimes(int left, int right) {
        
        vector<bool>isPrime(1e6+6,1);
        
        seive(isPrime,right);
        
        if(left-right==0){
            if(isPrime[left]){
                return {left,left};
            }
            else{
                return {-1,-1};
            }
        }
        
        vector<int>v;
        
        for(int i=left;i<=right;i++){
            
            if(isPrime[i])
                v.push_back(i);
            
        }
        
        int mini=INT_MAX;
        int a=-1;
        int b=-1;
        if(v.empty())return {a,b};
        for(int i=0;i<v.size()-1;i++){
            
            if(v[i+1]-v[i]<mini){
                
                a=v[i];
                b=v[i+1];
                mini=v[i+1]-v[i];
                
            }
            
        }
        
        return {a,b};
        
  
    }
};