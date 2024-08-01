class Solution {
public:
	int find(int a, vector<int>&parent){
	    if(parent[a]==a)
	    return a;
	    return find(parent[a],parent);
	}
	void Union(int a,int b,vector<int>&parent,vector<int>&rank){
	    int par_a=find(a,parent);
	    int par_b=find(b,parent);
	    if(rank[par_a]<rank[par_b]){
	        parent[par_a]=par_b;
	    }else if(rank[par_a]>rank[par_b]){
	        parent[par_b]=par_a;
	    }else{
	         parent[par_b]=par_a;
	         rank[par_a]++;
	    }
	}
    int makeConnected(int n, vector<vector<int>>& connections) {
         vector<int>rank(n,0);
        vector<int>parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        
        

    
int extraCables = 0;
        for (const auto& edge : connections) {
            if (find(edge[0], parent) != find(edge[1], parent)) {
                Union(edge[0], edge[1], parent, rank);
            } else {
                extraCables++;
            }
        }

        int components = 0;
        for (int i = 0; i < n; i++) {
            if (find(i, parent) == i) {
                components++;
            }
        }

        // To connect all components, we need (components - 1) cables
        return (components - 1 <= extraCables) ? components - 1 : -1;

    }
};