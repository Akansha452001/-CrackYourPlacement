class Solution {
public:
void pse(vector<int>&heights,vector<int>&prev){
    stack<int>st;
   for(int i=0;i<heights.size();i++){
    while(!st.empty() && heights[st.top()]>heights[i]){
        st.pop();
    }
    if(st.empty()){
        prev.push_back(-1);
    }else{
    
    prev.push_back(st.top());
    }
    st.push(i);
   }
}
void nse(vector<int>&heights,vector<int>&next){
    stack<int>st;
   for(int i=heights.size()-1;i>=0;i--){
    while(!st.empty() && heights[st.top()]>=heights[i]){
        st.pop();
    }
    if(st.empty()){
        next.push_back(heights.size());
    }else{
   
    next.push_back(st.top());
    }
     st.push(i);
   }
   reverse(next.begin(),next.end());
}
    int largestRectangleArea(vector<int>& heights) {
        vector<int>next,prev;
        nse(heights,next);
        pse(heights,prev);
        int maxi=INT_MIN;
        for(int i=0;i<heights.size();i++){
            maxi=max(maxi,(heights[i]*(next[i]-prev[i]-1)));
        }
        return maxi;
    }
};