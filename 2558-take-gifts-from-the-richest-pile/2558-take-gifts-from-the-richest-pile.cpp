class Solution {
public:
    using ll = long long;
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>maxh;
        for(auto i:gifts)maxh.push(i);
        for(int i=0;i<k;i++){
            ll t = maxh.top();
            maxh.pop();
            maxh.push((floor)(sqrt((double)t)));
        }
        ll ans = 0;
        while(!maxh.empty()){
            ll a = maxh.top();
            ans+=a;
            maxh.pop();
        }
        return ans;
    }
};