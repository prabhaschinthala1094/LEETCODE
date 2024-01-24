class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n=cards.size();
        unordered_map<int,int>mp;
        int ans=INT_MAX;
        for(int i=0,j=0;j<n;j++){
            if(mp[cards[j]]>0){
                ans=min(ans,j-mp[cards[j]]+2);
                i=max(mp[cards[j]],i);
            }
            mp[cards[j]]=j+1;
        }
        return (ans!=INT_MAX)?ans:-1;
    }
};