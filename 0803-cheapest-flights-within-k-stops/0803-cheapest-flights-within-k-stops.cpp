class Solution {
public:
    int findCheapestPrice(int s, vector<vector<int>>& flights, int src, int dst, int k) {
        // Create adjacency list
        vector<vector<pair<int, int>>> adj(s);
        for (const auto& flight : flights) {
            adj[flight[0]].emplace_back(flight[1], flight[2]);
        }

        // Queue to store (stops, (node, current_cost))
        queue<pair<int, pair<int, int>>> q;
        // Distance table to store the minimum cost to reach a node with a certain number of stops
        vector<vector<int>> dist(s, vector<int>(k + 2, INT_MAX));
        
        // Initialize with starting point
        q.push({0, {src, 0}});
        dist[src][0] = 0;

        while (!q.empty()) {
            auto [stops, node_cost] = q.front();
            auto [node, cost] = node_cost;
            q.pop();
            
            if (stops > k) continue;
            
            for (const auto& [next, price] : adj[node]) {
                int new_cost = cost + price;
                // If a cheaper cost is found for the next node within the stops limit
                if (new_cost < dist[next][stops + 1]) {
                    dist[next][stops + 1] = new_cost;
                    q.push({stops + 1, {next, new_cost}});
                }
            }
        }

        // Find the minimum cost to reach the destination within k stops
        int min_cost = INT_MAX;
        for (int i = 0; i <= k + 1; ++i) {
            min_cost = min(min_cost, dist[dst][i]);
        }
        
        return min_cost == INT_MAX ? -1 : min_cost;
    }
};