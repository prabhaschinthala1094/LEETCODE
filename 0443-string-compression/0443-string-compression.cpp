class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int i=0,j=0;
        int cnt=0;
        vector<char>ans;
        while(i<=j && j<n)
        {
            if(chars[i]==chars[j])
            {
                cnt++;
                j++;
            }
            else
            {
                string s=to_string(cnt);
                ans.push_back(chars[i]);
          
                if(s.length()==1&&s[0]=='1')
                {
                }
                else
                { 
                    for(int k=0;k<s.length();k++)
                    {
                    
                        ans.push_back(s[k]);
                    } 
                }
                
                i=j;
                cnt=0;
            }
        }
        
        string s=to_string(cnt);
        ans.push_back(chars[n-1]);
        
        if(s.length()==1 && s[0]=='1')
        {
        }
        else
        {
            for(int i=0;i<s.length();i++)
            {
               
                ans.push_back(s[i]);
            }
         }
        
        
        chars=ans;
        return ans.size();
        
        
    }
};