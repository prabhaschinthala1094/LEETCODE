class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>ans(n);
        stack<pair<int,int>>s;
        ans[n-1]=0;
        for(int i=n-1;i>=0;i--){
                while(!s.empty()&&s.top().first<=temperatures[i]){
                    s.pop();
                }
                if(s.empty()){
                    ans[i]=0;
                }
                else{
                    ans[i]=s.top().second-i;
                }
                s.push({temperatures[i],i});
            }
        
        return ans;
    }
};