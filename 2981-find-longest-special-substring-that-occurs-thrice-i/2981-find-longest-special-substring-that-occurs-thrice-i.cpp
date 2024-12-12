class Solution {
public:
    bool valid (string &p){
        unordered_set<char>st;
        for(auto i:p){
            st.insert(i);
        }
        return (st.size() == 1);
    }
    int maximumLength(string s) {
        int n = s.size();
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            string a ;
            a+=s[i];
            mp[a]++;
            for(int j=i+1;j<n;j++){
                a+=s[j];
                mp[a]++;
            }
        }
        int len = 0;
        for(auto i:mp){
            string p = i.first;
            if(valid(p) && i.second>=3){
                len = max(len,(int)i.first.size());
            }
        }
        
        return (len==0)?-1:len;
    } 
};