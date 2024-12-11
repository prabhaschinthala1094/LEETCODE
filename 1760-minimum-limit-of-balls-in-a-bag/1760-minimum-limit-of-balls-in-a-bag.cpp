class Solution {
public:
    using ll = long long int;
    bool valid(ll mid ,vector<int>& nums, int m){
        ll cnt = 0;
        for(int i=0;i<nums.size();i++){
            double a = (double)nums[i]/(double)mid;
            double b = (double)(nums[i]/mid);
            cnt+= ((a==b)? (ll)(--a):(ll)(b));
            if(cnt>m)return 0;
        }
        return (cnt<=m);
    }
    int minimumSize(vector<int>& nums, int m) {
        ll n =nums.size();
        ll s=1,e=*max_element(nums.begin(),nums.end());
        while(s<=e){
            ll mid = (s+e)/2;
            if(valid(mid,nums,m)){
                e = mid -1 ;
            }
            else{
                s = mid + 1;
            }
        }
        return (int)s;
    }
};