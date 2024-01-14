class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int ss=s.size(),aa=a.size(),bb=b.size();
        vector<int>a1,b1;
        for(int i=0;i<=ss-aa;i++){
            string temp=s.substr(i,aa);
            if(temp==a)a1.push_back(i);
        }
        
        for(int i=0;i<=ss-bb;i++){
            string temp=s.substr(i,bb);
            if(temp==b)b1.push_back(i);
        }
        
        vector<int>ans;
        for(int i=0;i<a1.size();i++){
            for(int j=0;j<b1.size();j++){
                if(abs(a1[i]-b1[j])<=k){
                    ans.push_back(a1[i]);
                    break;
                }
            }
        }
        return ans;
    }
};