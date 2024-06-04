class Solution {
public:
    int longestPalindrome(string s) {
       unordered_map<char,int>mp;
        for(auto i:s)mp[i]++;
        int cnt =0;
        int maxi=0;
        int ok =0;
        for(auto i:mp){
            if(i.second%2!=0)ok=1;
            
            cnt+=(i.second)-(i.second&1);
        }
        cnt +=ok;
        return cnt;
    }
};