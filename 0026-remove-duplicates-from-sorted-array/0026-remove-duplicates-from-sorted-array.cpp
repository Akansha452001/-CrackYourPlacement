class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1)
        return 1;
        vector<int>ans;
        int i=0,j=0;
       while(i<nums.size() && j<nums.size()){
          while(j<nums.size() && nums[j]==nums[i]){
            j++;
          }
          ans.push_back(nums[i]);
          i=j;
          j++;
        }
        if(j==nums.size())
        ans.push_back(nums[i]);
        for(int i=0;i<ans.size();i++){
            nums[i]=ans[i];
            cout<<nums[i]<<" ";
        }
        
        return ans.size();
    }
};