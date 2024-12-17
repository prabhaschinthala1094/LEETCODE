class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int m = queries.size();
        vector<int>v,ans(m,0);
        vector<int>pre(n,0);
        pre[0] = (s[0] =='*')?1:0;
        for(int i=0;i<n;i++){
            if(i>0){
                pre[i] = pre[i-1] + ((s[i] =='*')?1:0);
            }
            if(s[i] == '|')v.push_back(i);
        }
        if(v.size() == 0 || v.size() == n)return ans;
        
        for(int i=0;i<m;i++){
            int left = queries[i][0];
            int right = queries[i][1];
            if(left == right)continue;
            auto l = lower_bound(v.begin(),v.end(),left);
            auto r = lower_bound(v.begin(),v.end(),right);
            if(l == v.end())l--;
            if(r==v.end() ||*r != right){
                r--;
            }
            ans[i] = (max(min(pre[*r] - pre[*l] , *r - *l),0));           
        }
        return ans;
    }
};