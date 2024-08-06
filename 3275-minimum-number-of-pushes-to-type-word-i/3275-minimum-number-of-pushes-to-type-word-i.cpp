class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mp;
        int sum=0;
        for(int i=0;i<word.length();i++){
            if(!mp.empty() && mp.find(word[i])!=mp.end()){
               mp[word[i]]*=2;
            }else
            mp[word[i]]+=(1+mp.size()/8);
            // if(mp.size()>8 * j){
            //     mp[word[i]]+=j;
            // }
        }
        for(auto it:mp){
            sum+=it.second;
        }
        return sum;
    }
};