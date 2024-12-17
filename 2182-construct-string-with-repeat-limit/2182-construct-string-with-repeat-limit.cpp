class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n = s.size();
        vector<int>mp(26,0);
        priority_queue<char>maxh;
        for(int i=0;i<n;i++){
            mp[s[i] - 'a']++;
        }
        for(int i=0;i<26;i++){
            if(mp[i]>0)maxh.push('a'+i);
        }
        string ans;
        while(!maxh.empty()){
            char top = maxh.top();
            maxh.pop();
            int num = min(repeatLimit,mp[top-'a']);
            mp[top- 'a'] -= num;
            ans.append(num, top);
            
            if(mp[top-'a']>0){
                if(maxh.empty())break;
                char temp2 = maxh.top();
                maxh.pop();
                mp[temp2 - 'a']--;
                ans+=temp2;
                if(mp[temp2-'a'] > 0)maxh.push(temp2);
                maxh.push(top);
            }
        }
       return ans;
        
        
    }
};