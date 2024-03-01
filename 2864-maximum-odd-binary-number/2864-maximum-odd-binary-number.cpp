class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(s.rbegin(),s.rend());
        int cnt = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')cnt++;
        }
        swap(s[s.size()-1],s[cnt - 1]);
        return s;
    }
};