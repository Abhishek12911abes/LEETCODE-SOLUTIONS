class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char,int>mp;
        int maxLen=0;
        bool dup=false;
        for(int i=0;i<s.size();i++){
            if(mp.count(s[i])){
                maxLen=max(maxLen,(i-mp[s[i]]-1));
                dup=true;
            }
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]=i;
            }
        }
        if(!dup){
            return -1;
        }
        return maxLen;
    }
};