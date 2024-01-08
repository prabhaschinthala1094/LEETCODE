class Solution {
public:
    bool check(int mid,vector<int>& position, int m) {
        int cnt=1,prev=position[0];
        for(int i=1;i<position.size();i++){
            if(position[i]-prev>=mid){
                cnt++;
                prev=position[i];
            }
        }
        return (cnt>=m);
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int s=1,n=position.size(),e=position[n-1]-position[0],mid;
        while(s<=e){
            mid=s+(e-s)/2;
            if(check(mid,position,m)){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return s-1;
    }
};