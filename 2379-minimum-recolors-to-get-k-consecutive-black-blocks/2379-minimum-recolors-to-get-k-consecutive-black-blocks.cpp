class Solution {
public:
    int minimumRecolors(string s, int k) {
        int n=s.size();

        unordered_map<char,int>mp;
        int minLen=INT_MAX;
        int i=0,j=0;
        while(j<n){
            mp[s[j]]++;
            if(j-i+1>k){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
            if(j-i+1==k){
                minLen=min(minLen,k-mp['B']);
            }
            j++;
        }
        return minLen;
        
    }
};