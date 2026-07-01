class Solution {
public:
    bool isPalindrome(string &s , int i , int j){
        if(i>j){
            return false;
        }
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++,j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int maxLen=-1;
        int start_i=-1;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(s,i,j)){
                    if(j-i+1>maxLen){
                        maxLen=j-i+1;
                        start_i=i;
                    }
                }
            }
        }
        return s.substr(start_i,maxLen);
        
    }
};