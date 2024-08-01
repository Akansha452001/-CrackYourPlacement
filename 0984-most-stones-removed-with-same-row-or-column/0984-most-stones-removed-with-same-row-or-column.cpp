//contection between two use disjoint set
//total stones-no. of components
class Solution {
public:
    int find(int a, vector<int>& parent) {
        if (parent[a] == a)
            return a;
        return parent[a] = find(parent[a], parent); // Path compression
    }

    void Union(int a, int b, vector<int>& parent, vector<int>& rank) {
        int par_a = find(a, parent);
        int par_b = find(b, parent);
        if (par_a != par_b) {
            if (rank[par_a] < rank[par_b]) {
                parent[par_a] = par_b;
            } else if (rank[par_a] > rank[par_b]) {
                parent[par_b] = par_a;
            } else {
                parent[par_b] = par_a;
                rank[par_a]++;
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int maxrow = 0, maxcol = 0;
        for (const auto& stone : stones) {
            maxrow = max(maxrow, stone[0]);
            maxcol = max(maxcol, stone[1]);
        }

        vector<int> rank(maxrow + maxcol + 2, 0);
        vector<int> parent(maxrow + maxcol + 2);
        for (int i = 0; i <= maxrow + maxcol + 1; ++i) {
            parent[i] = i;
        }

        unordered_map<int, int> uniquenodes;
        for (auto stone : stones) {
            int noderow = stone[0];
            int nodecol = stone[1] + maxrow + 1;
            Union(noderow, nodecol, parent, rank);
            uniquenodes[noderow] = 1;
            uniquenodes[nodecol] = 1;
        }

        int cnt = 0;
        for ( auto it : uniquenodes) {
            if (find(it.first, parent) == it.first)
                cnt++;
        }

        return stones.size() - cnt; // Total stones - number of components
    
    }
};