class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();

        int i=0;
        string word;
        string ans;
        while(i<n){
            if(s[i]==' '){
                reverse(begin(word),end(word));
                ans+=word;
                ans+=' ';
                word.clear();
            }
            else{
                word+=s[i];
            }
            i++;
        }
        reverse(begin(word),end(word));
        return ans+word;
        
    }
};