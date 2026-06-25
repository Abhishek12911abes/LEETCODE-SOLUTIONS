class Solution {
public:
    int countHomogenous(string s) {
        int n=s.size();
        int mod=1e9+7;
        long long ans=0;
        unordered_map<char,int>mp;
        int i=0,j=0;
        while(j<n){
            mp[s[j]]++;
            while(mp.size()>1){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
            ans=(ans+(j-i+1))%mod;
            j++;
        }
        return ans%mod;;
    }
};