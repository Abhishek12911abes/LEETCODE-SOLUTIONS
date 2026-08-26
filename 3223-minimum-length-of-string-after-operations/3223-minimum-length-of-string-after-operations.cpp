class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        if(s.size()<3){
            return n;
        }
        unordered_map<char,int>mp;
        for(char c : s){
            mp[c]++;
        }
        int count=0;
        for(auto &it : mp){
            while(it.second>=3){
                it.second-=2;
                count+=2;
            }
        }
        return n-count;
        
    }
};