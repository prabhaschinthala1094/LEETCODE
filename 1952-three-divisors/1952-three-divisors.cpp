class Solution {
public:
    
    bool isThree(int n) {
        int div=2;
        for(int i=2;i<n && div<=3;i++) {
            if(n%i==0)div++;
        }
        return div==3;
    }
};