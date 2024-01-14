class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int>mp1(26,0),mp2(26,0);
        set<int>s1,s2;
        for(auto it:word1){
            mp1[it-'a']++;
            s1.insert(it-'a');
        }
        for(auto it:word2){
            mp2[it-'a']++;
            s2.insert(it-'a');
        }
        sort(mp1.begin(),mp1.end());
        sort(mp2.begin(),mp2.end());
        
        return mp1==mp2 && s1==s2;
    }
};