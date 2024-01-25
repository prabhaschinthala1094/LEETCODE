class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<list<char>>mp;
        int n=s.size();
        if(n<=10)return {};
        set<string>check;
        vector<string> ans;
        list<char>temp;
        int j=0;
        
        while(j<=n){
            while(j<10){
                temp.push_back(s[j]);
                j++;
            }
           
            if(mp.find(temp)!=mp.end()){
                string p;
                for(auto it:temp)p+=it;
                check.insert(p);
             
            }
            mp.insert(temp);  
             temp.pop_front();
             temp.push_back(s[j]);
            j++;
        }
        for(auto it:check)ans.push_back(it);
        return ans;
    }
};