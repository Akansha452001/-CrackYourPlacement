
class Solution {
public:
    int timer = 1;

    void dfs(int node, int parent, std::vector<bool>& vis, std::vector<std::vector<int>>& adj, int time_in_insertion[], int low[], std::vector<std::vector<int>>& bridges) {
        vis[node] = true;
        time_in_insertion[node] = low[node] = timer++;
        
        for (auto it : adj[node]) {
            if (it == parent) continue; // Skip the edge leading to the parent
            
            if (!vis[it]) {
                dfs(it, node, vis, adj, time_in_insertion, low, bridges);
                low[node] = std::min(low[node], low[it]);
                
                // Bridge condition
                if (low[it] > time_in_insertion[node]) {
                    bridges.push_back({node, it});
                }
            } else {
                // Update low[node] for back edges
                low[node] = std::min(low[node], time_in_insertion[it]);
            }
        }
    }

    std::vector<std::vector<int>> criticalConnections(int n, std::vector<std::vector<int>>& connections) {
        std::vector<bool> vis(n, false);
        std::vector<std::vector<int>> adj(n);
        std::vector<std::vector<int>> bridges;
        
        for (const auto& connection : connections) {
            int u = connection[0];
            int v = connection[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int time_in_insertion[n];
        int low[n];
        
        // Start DFS from the first node (assuming 0-indexed graph)
        dfs(0, -1, vis, adj, time_in_insertion, low, bridges);
        
        return bridges;
    }
};
