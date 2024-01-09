class Solution {
public:
    int countTriples(int n) {
        vector<int>v(n);
        unordered_set<int>s;
        for(int i=1;i<=n;i++){
            v[i-1]=i*i;
            s.insert(v[i-1]);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(s.find(v[i]+v[j])!=s.end()){
                    cnt+=2;
                }
            }
        }
        return cnt;
    }
};