class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       
        vector<vector<int>> ans;
    if (nums.size() < 4) return ans;

    sort(nums.begin(), nums.end());

   for(int i=0;i<=nums.size()-4;i++){
    if(i>0 && nums[i-1]==nums[i])
    continue;
    for(int j=i+1;j<=nums.size()-3;j++){
       if(j>i+1 && nums[j-1]==nums[j]){
        continue;
       }
       int l=j+1,m=nums.size()-1;
       while(l<m){
        long long sum=(long long)nums[i]+nums[j]+nums[l]+nums[m];
        
        if(sum==target){
            ans.push_back({nums[i],nums[j],nums[l],nums[m]});
            while(l<m && nums[l+1]==nums[l]) l++;
            while(l<m && nums[m-1]==nums[m]) m--;
            l++;
            m--;
        }else if(sum<target)
        l++;
        else
        m--;
       }
    }

   }
   return ans;
    }
};