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
        int minLength = min(str1.length(), str2.length());

        for (int i = 1; i <= minLength; i++) {
            // Only consider substrings that are possible divisors of both
            // strings
            
                string length = str1.substr(0, i);

                // Check if `length` can construct both `str1` and `str2`
                if (check(length, str1) && check(length, str2)) {
                    ans = length; // Update the answer with the current valid
                                  // divisor
                }
            
        }
        return ans;
    }
};