class Solution {
public:
    bool check(const string& length, const string& str) {
        int n = length.length();
        if (str.length() % n != 0)
            return false;

        for (int i = 0; i < str.length(); i += n) {
            if (str.substr(i, n) != length)
                return false;
        }
        return true;
    }


    string gcdOfStrings(string str1, string str2) {
        string ans;
        int minLength;
        string temp;
       if(str1.length()<str2.length()){
        minLength=str1.length();
        temp=str1;
       }
       else{
         minLength=str2.length();
        temp=str2;
       }
       
        for (int i = 1; i <= minLength; i++) {
            
            
                string length = temp.substr(0, i);

                
                if (check(length, str1) && check(length, str2)) {
                    ans = length; 
                }
            
        }
        return ans;
    }
};