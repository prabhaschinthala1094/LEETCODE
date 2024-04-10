class Solution {
public:
    bool isPossible(int mid,vector<int>& position, int m) {
        int n = position.size();
        int cnt = 1;
        int prev = position[0];
        for(int i=1;i<n;i++) {
            if(position[i] - prev >= mid){
                prev = position[i];
                cnt++;
            }
        }
        return cnt >= m; 
        
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int s = 0;
        int e = *max_element(position.begin(),position.end())-*min_element(position.begin(),position.end());
            
        while(s<=e) {
            int mid = s+(e-s)/2;
            if(isPossible(mid,position,m)){
                s = mid +1 ;
            }
            else{
                e = mid -1;
            }
        }
        return e;
    }
};