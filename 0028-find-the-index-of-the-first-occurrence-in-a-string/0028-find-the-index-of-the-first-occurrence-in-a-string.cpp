class Solution {
public:
    int strStr(string haystack, string needle) {
        if( haystack==needle)
        return 0;
        if(haystack.length()<needle.length())
        return -1;
        for(int i=0;i<=haystack.length()-needle.length();i++){
            int j=0;
            int t=i;

            while(j<needle.size() && t<haystack.length() && haystack[t]==needle[j]){
                t++;
                j++;
            }
            if(j==needle.size()){
                return i;
            }
        }
        return -1;
    }
};