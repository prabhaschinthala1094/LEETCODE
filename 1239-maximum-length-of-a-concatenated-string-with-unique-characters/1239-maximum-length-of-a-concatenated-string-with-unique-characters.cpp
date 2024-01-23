class Solution {
public:
    unordered_map<string,int>mp;
    bool hasDuplicate(string &a,string &b){
        vector<bool>freq(26,0);
        for(auto &it:a){
            if(freq[it-'a'])return 1;
            freq[it-'a']=1;
        }
        for(auto &it:b){
            if(freq[it-'a'])return 1;
            freq[it-'a']=1;
        }
        return 0;
    }
    int solve(int i,vector<string>&arr,string temp){
        if(i>=arr.size())return temp.size();
        
        if(mp.find(temp)!=mp.end())return mp[temp];
        
        int include=0;
        int exclude=0;
        
        if(hasDuplicate(arr[i],temp)){
            exclude=solve(i+1,arr,temp);
        }
        else{
            exclude=solve(i+1,arr,temp);
            include=solve(i+1,arr,temp+arr[i]);
            
        }
        return mp[temp]=max(include,exclude);
        
    }
    int maxLength(vector<string>& arr) {
        string temp="";
        int n=arr.size();
        int i=0;
        return solve(i,arr,temp);
    }
};