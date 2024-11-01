class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        if(n <3)return s;
        string ans;
        ans += s[0];
        for(int i=1;i<n-1;i++){
            if(s[i-1]!=s[i] || s[i+1]!=s[i])ans+=s[i];
        }
        ans+=s[n-1];
        return ans;
    }
};