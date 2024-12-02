class Solution {
public:
    int isPrefixOfWord(string word, string s) {
        int n = word.size();
        string t;
        int p = 1;
        for(int i=0;i<n;i++){
            if(word[i] == ' '){
                
                t.clear();
                p++;
                continue;
            }
            t+=word[i];
            // cout<<t<<" ";
            if(t==s){
                return p;
            }
        }
        return -1;
    }
};