class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        int count=0;
        int depth=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                count++;
                depth = max(count,depth);
            }
            else if(s[i]==')')
            {
                count--;
            }
        }
        return depth;
        
    }
};