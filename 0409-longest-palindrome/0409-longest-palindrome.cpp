class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        for(char ch : s){
            mp[ch]++;
        }

        int res=0;
        bool odd=false;
        for(auto &it : mp){
            if(it.second%2==0){
                res+=it.second;
            }
            else{
                int cantake=it.second/2;
                odd=true;
                res+=(cantake*2);
                it.second=1;
            }
        }

        return (odd==true)?(res+1):res;
        
    }
};