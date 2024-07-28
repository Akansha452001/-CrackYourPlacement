class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        // Create an adjacency list for the graph
        vector<vector<int>> adj(n);
        for (auto e : edges) {
            adj[e[0] - 1].push_back(e[1] - 1); // Add edge from node e[0] to e[1]
            adj[e[1] - 1].push_back(e[0] - 1); // Add edge from node e[1] to e[0]
        }

        // Initialize distances with large values
        vector<pair<int, int>> dist(n, {1e9, 1e9});
        // Priority queue to process nodes in increasing order of their current travel time
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Start from the first node (index 0), with initial time 0
        dist[0] = {0, 1e9}; // First element is 0, second element is still a large value
        pq.push({0, 0}); // Push the starting node and its time to the priority queue

        // Process nodes until the priority queue is empty
        while (!pq.empty()) {
            auto [currTime, node] = pq.top(); // Get the node with the smallest current time
            pq.pop(); // Remove it from the priority queue

            // Skip processing if we have already found a shorter second minimum time
            if (currTime > dist[node].second) {
                continue;
            }

            // Calculate the new time after traveling to the next node
            int newTime = currTime + time;
            // Determine the state of the traffic light (red or green)
            int temp = currTime / change;
            if (temp % 2 == 1) // If the light is red
                newTime = (temp + 1) * change + time; // Wait for the green light

            // Explore the neighbors of the current node
            for (auto adjNode : adj[node]) {
                // If the new time is shorter than the shortest known time to the neighbor
                if (dist[adjNode].first > newTime) {
                    dist[adjNode].second = dist[adjNode].first; // Update second shortest time
                    dist[adjNode].first = newTime; // Update shortest time
                    pq.push({dist[adjNode].first, adjNode}); // Push the neighbor to the priority queue
                }
                // If the new time is the same as the shortest known time to the neighbor
                else if (dist[adjNode].first == newTime) {
                    continue; // Skip processing
                }
                // If the new time is shorter than the second shortest known time to the neighbor
                else if (dist[adjNode].second > newTime) {
                    dist[adjNode].second = newTime; // Update second shortest time
                    pq.push({dist[adjNode].second, adjNode}); // Push the neighbor to pq
                }               
            }
        }
        // return second value of the last index
        return dist[n-1].second;
    }
};