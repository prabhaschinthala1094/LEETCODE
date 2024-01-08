class Solution {
public:
    string reverseWords(string s) {
        vector<string>ans;
        string p="";
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]!=' ')
            {
                p+=s[i];
            }
            else
            {
                if(!p.empty())
                {
                    ans.push_back(p);
                }
                p.clear();
            }
        }   
         if(!p.empty())
        {
            ans.push_back(p);
        }
       
        s.clear();

        for(int i=ans.size()-1;i>=0;i--)
        {
            for(auto it: ans[i])
            {
                s+=it;
            }
            
            if(i!=0)
            {
                s+=' ';
            }
            
        }
        return s;

    }
};