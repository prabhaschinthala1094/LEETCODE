class Solution {
public:
    bool solve(int mid ,vector<int>& pos, int m) {
        int n = pos.size();
        int curr = pos[0];
        m-=1;
        for(int i=1;i<n;i++){
            if(pos[i]-curr>=mid){
                curr = pos[i];
                m--;
            }
        }
        return (m<=0);
    }
    int maxDistance(vector<int>& pos, int m) {
        int n = pos.size();
        sort(pos.begin(),pos.end());
        int e = pos[n-1];
        int s = 0;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(solve(mid,pos,m)){
                s = mid + 1;
            }else{
                e = mid -1;
            }
        }
        return e;
    }
};