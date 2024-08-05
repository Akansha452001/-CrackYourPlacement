class Solution {
public:
   //yi + yj + |xi - xj|
   //yi+ yj + xj-xi
   //(yi-xi)+(xj+yj) to make it max we neeed(yi-xi)large
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>>pq;
        //<(yi-xi),xi>
        int maxi=INT_MIN;
        for(int i=0;i<points.size();i++){
            while(!pq.empty() && points[i][0]-pq.top().second>k){
                pq.pop();
            }
                if(!pq.empty()){
               int ans=points[i][0]+points[i][1]+pq.top().first;
               maxi=max(maxi,ans);
            }

            pq.push({points[i][1]-points[i][0],points[i][0]});

        }
        return maxi;
    }
};