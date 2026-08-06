class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int maxLen=0;
        int i=0,j=0;
        unordered_map<char,int>mp;
        while(j<n){
            mp[s[j]]++;
            while(mp.size()!=j-i+1){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
            maxLen=max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
        
    }
};