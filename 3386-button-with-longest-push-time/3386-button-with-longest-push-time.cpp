class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int n = events.size();
        int t =0;
        int ind = 1e6;
        int prev = 0;
        for(int i=0;i<n;i++){
            if(t== events[i][1] - prev){
                ind = min(events[i][0],ind);
            }
            if(t<events[i][1] - prev){
                ind = events[i][0];
                t = events[i][1] - prev;
            }
            
             prev = events[i][1];
        }
        return ind;
    }
};