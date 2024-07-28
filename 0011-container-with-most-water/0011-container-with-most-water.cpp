class Solution {
public:

// width decrease height increase
    int maxArea(vector<int>& height) {
        int maxi=INT_MIN;
       int l=0,r=height.size()-1;
       while(l<r){
        int h=min(height[l],height[r]);
        int w=r-l;
        maxi=max(h*w,maxi);
        if(height[l]>height[r]){
            r--;
        }else {
           l++;
        }
       }
        return maxi;
    }
};