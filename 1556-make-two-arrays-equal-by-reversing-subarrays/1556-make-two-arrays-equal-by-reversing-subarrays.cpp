class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int>mp;
       for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
       } 
       for(int i=0;i<target.size();i++){
        if(mp.find(target[i])!=mp.end()){
            mp[target[i]]--;
           if(mp[target[i]]==0){
            mp.erase(target[i]);
           }
        }
       
       }
       if(mp.empty()){
        return true;

       }
       return false;
    }
};