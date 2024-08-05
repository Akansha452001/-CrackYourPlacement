class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxreach=nums[0];
    for(int i=1;i<nums.size();i++){
        if(i>maxreach)
        return false;
        maxreach=max(maxreach,i+nums[i]);
    }
    return true;
}

};