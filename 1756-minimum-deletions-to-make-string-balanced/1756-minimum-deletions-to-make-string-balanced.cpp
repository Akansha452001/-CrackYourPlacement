class Solution {
public:
    int minimumDeletions(string s) {
        int count=0;
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(!st.empty() && st.top()=='b' && s[i]=='a'){
                count++;
                st.pop();
            continue;
            }
            st.push(s[i]);

        }
        return count;

    }
};