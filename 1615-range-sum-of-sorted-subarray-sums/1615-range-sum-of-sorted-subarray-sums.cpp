class Solution {
public:
// 1 3 6 10 
// 1 3 6 10 
int M=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>ans;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                ans.push_back(sum);
            }
        }
        
        sort(ans.begin(),ans.end());
    //    for(int i=0;i<ans.;i++){
    //     cout<<ans[i];
        int result=0;
        for(int i=left-1;i<right;i++){
            result=(result+ans[i])%M;
        }
        return result;
    }
};