class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int n=s.size();
        int maxi=0;
        for(int i=0,j=0;j<n;j++){
            if(mp[s[j]]>0){
                i=max(mp[s[j]],i);
            }
            maxi=max(maxi,j-i+1);
            mp[s[j]]=j+1;
        }
      return maxi;  
    }
};