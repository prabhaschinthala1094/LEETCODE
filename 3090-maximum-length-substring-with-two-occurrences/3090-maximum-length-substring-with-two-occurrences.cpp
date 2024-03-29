class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int maxi=0;
        for(int i=0;i<n;i++) {
            vector<int>f(26,0);
            int j=i;
            for(;j<n;j++){
                f[s[j]-'a']++;
                if(f[s[j]-'a']==3){
                    break;
                    
                }
            }
            maxi= max(maxi,j-i);
            
        }
        return maxi;
    }
};