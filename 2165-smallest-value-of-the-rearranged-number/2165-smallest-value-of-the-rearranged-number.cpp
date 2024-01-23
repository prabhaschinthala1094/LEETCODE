class Solution {
public:
    long long smallestNumber(long long num) {
        if(num==0)return 0;
        vector<long long>v;
        long long sign=1;
        if(num<0){
            num*=-1LL;
            sign=-1;
        }
        while(num){
            v.push_back(num%10LL);
            num=num/10LL;
        }
        long long ans=1;
        int cnt=0;
        int i=0;
            
        if(sign==1){
            sort(v.begin(),v.end());
            while(v[i]==0&&i<v.size()){
                i++;
                cnt++;
            }
            if(i==v.size())return 0;
            ans*=v[i];
            ans*=pow(10LL,cnt);
            i++;
        }
        else{
            sort(v.rbegin(),v.rend());
        }
        for(;i<v.size();i++){
            if(i>0){ans*=10LL;              
            ans+=v[i];}
            else{
                ans=v[i];
            }
        }
        
        return (sign==1)?ans:-1LL*ans;
        
    }
};