class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.size();
        if(s.size()==k){
            return true;
        }
        else if(k>n){
            return false;
        }
        vector<int>freq(26,0);
        for(char c : s){
            freq[c-'a']++;
        }
        int odd=0;
        for(int i=0;i<26;i++){
            if(freq[i]%2==1){
                odd++;
            }
        }
        return odd<=k;


        
    }
};