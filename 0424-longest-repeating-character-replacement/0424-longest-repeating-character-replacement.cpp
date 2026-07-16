class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int i=0,j=0;
        unordered_map<int,int> mp;
        int maxLen=-1; 
        int maxFreq=0;     
        while(j<n){
            mp[s[j]]++;
            maxFreq=max(maxFreq,mp[s[j]]);
            while((j-i+1)-maxFreq>k){
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