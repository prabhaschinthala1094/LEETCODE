class Solution {
public:
    bool isSubsequence(string s, string t) {
     int n=t.size();
     int m=s.size();
     
     if(n<m)
     {
        return false;
     }
    
     int j=0;
     for(int i=0;i<n && j<m;i++)
     {
        if(s[j]==t[i])
        {
            j++;
        }
        
     }
     if(j==m)
    {
        return true;
    }
    else
    {return false;
    }
   
    }
};