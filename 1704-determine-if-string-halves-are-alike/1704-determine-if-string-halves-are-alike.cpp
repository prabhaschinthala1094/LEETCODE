class Solution {
public:
    bool isVow(char a){
        return (a=='a'||a=='e'||a=='i'||a=='o'||a=='u'||a=='A'||a=='E'||a=='I'||a=='O'||a=='U');
    }
    bool halvesAreAlike(string s) {
        int cnt=0;
        for(auto it:s){
            if(isVow(it))cnt++;
        }
        if(cnt&1)return 0;
        int t=0;
        for(int i=(s.size()/2)-1;i>=0;i--){
            if(isVow(s[i]))t++;
        }
        return (t==cnt/2)?1:0;
    }
};