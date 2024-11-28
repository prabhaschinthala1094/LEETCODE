class Solution {
public:
    
    int dijkstra(unordered_map<int, vector<pair<int, int>>>& graph, int start, int end, int n) {
        vector<int> distances(n, INT_MAX);
        distances[start] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [current_distance, current_node] = pq.top();
            pq.pop();

            if (current_node == end) {
                return current_distance;
            }

            if (current_distance > distances[current_node]) {
                continue;
            }

            for (auto& [neighbor, weight] : graph[current_node]) {
                int distance = current_distance + weight;
                if (distance < distances[neighbor]) {
                    distances[neighbor] = distance;
                    pq.push({distance, neighbor});
                }
            }
    }
    
    return distances[end];
}

 vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
    unordered_map<int, vector<pair<int, int>>> graph;
    

    for (int i = 0; i < n - 1; ++i) {
        graph[i].push_back({i + 1, 1});
    }
    
    vector<int> results;
    
    for (int i=0;i<queries.size();i++) {
        
            int u = queries[i][0];
            int v = queries[i][1];
            
            graph[u].push_back({v, 1});
            int shortest_path = dijkstra(graph, 0, n - 1, n);
            results.push_back(shortest_path);
        
    }
    
    return results;
}

    
   
};