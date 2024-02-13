class Solution {
public:
    bool valid(int i,int j,string &s) {
        if(i>j)return 1;
        if(s[i]==s[j])return valid(i+1,j-1,s);
        return 0;
    }
    string firstPalindrome(vector<string>& words) {
        int n=words.size();
        for(int i=0;i<n;i++) {
            if(valid(0,words[i].size()-1,words[i]))return words[i];
        }
        return "";
    }
};