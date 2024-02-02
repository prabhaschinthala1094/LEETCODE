class Solution {
public:
    vector<int>ans;
    void solve(int low,int high,int num,int i) {
        if(i>10 || num>high)return ;
        if(num<=high && num>=low)ans.push_back(num);
        solve(low,high,num*10+i,i+1);
    }
    vector<int> sequentialDigits(int low, int high) {
        for(int i=1;i<=9;i++) {
            solve(low,high,0,i);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};