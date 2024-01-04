class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        map<int,int>mp;
        for(auto it:nums)mp[it]++;
        for(auto it:mp){
            if(it.second==1)return -1;
            if(it.second%3==0){
                ans+=it.second/3;
            }
            else if(it.second%3==2){
                ans+=it.second/3;
                ans+=1;
            }
            else{
                int t=it.second-4;
                ans+=t/3;
                ans+=2;
            }
        }
        return ans;
    }
};