class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>s;
        
        for(int i=0;i<=nums.size()-3;i++){
            int sum=nums[i];
            int j=i+1,k=nums.size()-1;
            while(j<k){
                if(sum+nums[j]+nums[k]==0){
                    s.insert({sum,nums[j],nums[k]});
                    j++;
                    k--;
                }else if(sum+nums[j]+nums[k]<0){
                    j++;
                }else
                k--;
            }
        }
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
        
    }
};