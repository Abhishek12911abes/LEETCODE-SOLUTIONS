class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int ans=0;
        int count=0,val=1;
        unordered_map<char,int>mp;
        for(char ch : word){
            mp[ch]++;
        }
        sort(begin(word),end(word),[&](char a , char b){
            if(mp[a]==mp[b]){
                return a>b;
            }
            return mp[a]>mp[b];
        });

        // iiiiiiaabbccddeeffgghh
        for(int i=0;i<n;i++){
            if(i>0 && word[i]!=word[i-1])
                count++;
            if(count>0 && count%8==0 && word[i]!=word[i-1]){
                val++;
            }
            ans+=val;
        }
        return ans;

        
    }
};