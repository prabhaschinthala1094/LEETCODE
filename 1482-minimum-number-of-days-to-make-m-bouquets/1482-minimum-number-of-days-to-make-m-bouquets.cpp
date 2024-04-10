class Solution {
public:
    bool isPossible(int days,vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int cnt = 0;
        int num = k;
        for(int i=0;i<n;i++){
            if(num == 0){
                cnt++;
                num = k;
            }
            if(bloomDay[i]<=days){
                num--;
            }
            else{
                num = k;
            }
        }
        if(num == 0)cnt++;
        return (cnt >= m);
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long tot = m;
        tot = tot*k;
        if((long long)n<tot)return -1;
        int s=*min_element(bloomDay.begin(),bloomDay.end());
        int e=*max_element(bloomDay.begin(),bloomDay.end());
        // cout<<s<<" "<<e<<endl;
        int ans = e;
        while(s<=e) {
            int mid = s+(e-s)/2;
            if(isPossible(mid,bloomDay,m,k)){
                e = mid - 1;
                ans = mid;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};