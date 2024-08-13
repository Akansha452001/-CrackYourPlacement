class Solution {
public:
void solve(vector<int>& candidates, int target,int idx,vector<int>&ans,vector<vector<int>>&result){
    if(target==0)
    {
        result.push_back(ans);
        return;
    }
    for(int i=idx;i<candidates.size();i++){
        if(i>idx && candidates[i]==candidates[i-1]) 
        continue;
        if(candidates[i]>target)
        break;
        ans.push_back(candidates[i]);
        solve(candidates,target-candidates[i],i+1,ans,result);
        ans.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>ans;
        vector<vector<int>>result;
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,0,ans,result);
        return result;
    }
};