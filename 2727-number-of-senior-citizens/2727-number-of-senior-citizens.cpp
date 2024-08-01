class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt=0;
        for(int i=0;i<details.size();i++){
            string str=details[i];
            int num=10 * (str[11]-'0')+(str[12]-'0');
            if(num>60)
            cnt++;
        }
        return cnt;
    }
};