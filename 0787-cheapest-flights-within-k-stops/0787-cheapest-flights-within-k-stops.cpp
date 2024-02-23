class Solution {
public:
    #define pi pair<int,pair<int,int>>
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto it:flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pi>q;
        vector<int>cost(n,1e9);
        cost[src]=0;
        q.push({0,{src,0}});
        while(!q.empty())
        {
            int stops=q.front().first;
            int node=q.front().second.first;
            int price=q.front().second.second;
            q.pop();
            if(stops>k)continue;
            for(auto it: adj[node])
            {
                int to=it.first;
                int co=it.second;
                if(co+price<cost[to] && stops<=k)
                {
                    cost[to]=co+price;
                    q.push({stops+1,{to,co+price}});
                }
            }
        }
        if(cost[dst]==1e9)return -1;
        return cost[dst];

    }
};