class Solution {
public:
    static bool cmp(pair<char,int>&a,pair<char,int>&b)
    {
        if(a.second==b.second)
        {
            return a.first<b.first;
        }
        else
        {
            return a.second>b.second;
        }
    }
    string frequencySort(string s) {
        map<char,int>mp;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        vector<pair<char,int>>v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),cmp);
        string q="";
        for(auto it:v)
        {
            while(it.second>0)
            {
                q+=it.first;
                it.second--;
            }
        }
        return q;
    }
};