class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // if(n==k)
        // return -1;
        int p=times.size();
        int l=times[0].size();
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<p;i++){
            
                adj[times[i][0]].push_back({times[i][1],times[i][2]});
            
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>time(n+1,INT_MAX);
        time[0]=0;
        pq.push({0,k});
        time[k]=0;
        int temp;
        while(!pq.empty()){
           int t=pq.top().first;
           int node=pq.top().second;
           pq.pop();
           temp=t;
           for(auto neighbor:adj[node]){
            if(t+neighbor.second<time[neighbor.first]){
                time[neighbor.first]=t+neighbor.second;
                pq.push({time[neighbor.first],neighbor.first});
            }
           }
        }
int maxi=*max_element(time.begin(),time.end());
        return maxi==INT_MAX?-1:maxi;
    }
};