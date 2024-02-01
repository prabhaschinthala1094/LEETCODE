class Solution {
public:
    
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n=watchedVideos.size();
       queue<pair<int,int>>q;
        unordered_map<int,unordered_set<int>>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<friends[i].size();j++){
                
                mp[i].insert(friends[i][j]);
                mp[friends[i][j]].insert(i);
                
            }
        }
        for(auto it:mp){
            cout<<it.first<<"->";
            for(auto p:it.second){
                cout<<p<<",";
            }
            cout<<endl;
        }
        q.push({0,id});
        vector<int>vis(n,0);
        vis[id]=1;
        vector<int>frnds;
        
        while(!q.empty()){ 
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto [currlvl,currId] = q.front();
                q.pop();
                if(currlvl == level){
                    frnds.push_back(currId);
                    break;
                }
                for(auto it:mp[currId]){
                    if(!vis[it]){
                        q.push({currlvl+1,it});
                        vis[it]=1;
                    }
                }
            }
        }
        unordered_map<string,int>freq;
        for(auto it:frnds){
            for(auto p:watchedVideos[it]){
                freq[p]++;
            }
        }
        vector<pair<int,string>>ans;
        for(auto it:freq){
            ans.push_back({it.second,it.first});
        }
        sort(ans.begin(),ans.end());
        vector<string>last;
        for(auto it:ans){
            last.push_back(it.second);
        }
        return last;
    }
};