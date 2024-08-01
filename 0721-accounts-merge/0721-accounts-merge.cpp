class Disjoint{
    vector<int>rank;
    vector<int>parent;
    public: 
    Disjoint(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<n+1;i++){
            parent[i]=i;
        }
    }
    int find(int a){
	    if(parent[a]==a)
	    return a;
	    return find(parent[a]);
	}
	void Union(int a,int b){
	    int par_a=find(a);
	    int par_b=find(b);
	    if(rank[par_a]<rank[par_b]){
	        parent[par_a]=par_b;
	    }else if(rank[par_a]>rank[par_b]){
	        parent[par_b]=par_a;
	    }else{
	         parent[par_b]=par_a;
	         rank[par_a]++;
	    }
	}
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int>mp;
        Disjoint ds(accounts.size());
       for(int i=0;i<accounts.size();i++){
        for(int j=1;j<accounts[i].size();j++){
            if(mp.find(accounts[i][j])==mp.end())
            mp[accounts[i][j]]=i;
            else
            ds.Union(i,mp[accounts[i][j]]);
        }


       }
       vector<vector<string>>ans(accounts.size());
       for(auto it:mp){
        
          string mail=it.first;
          int node=ds.find(it.second);
          ans[node].push_back(mail);



       } 
       vector<vector<string>>result;
       for(int i=0;i<ans.size();i++){
        if(ans[i].size()!=0){
            sort(ans[i].begin(),ans[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:ans[i])
            temp.push_back(it);
            result.push_back(temp);
        }
       }

       return result;
    }
};