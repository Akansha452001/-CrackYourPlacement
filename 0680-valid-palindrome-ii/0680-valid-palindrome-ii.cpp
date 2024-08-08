class Solution {
public:
bool valid(string s, int i,int j){
    while(i<j){
        if(s[i]==s[j]){
            i++;
            j--;
        }else
        return false;
    }
   
    return true;
    
}
    bool validPalindrome(string s) {
       if(valid(s,0,s.length()-1)==true){
        return true;
       }
       int i=0,j=s.length()-1;
       while(i<j){
          if(s[i]==s[j]){
            i++;
            j--;
          }else{
            return valid(s,i+1,j) || valid(s,i,j-1);
          }
       }
       return true;
    }
};