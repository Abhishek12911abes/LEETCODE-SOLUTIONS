class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        unordered_map<char, int> mp;
        for (char c : s1) {
            mp[c]++;
        }
        int i = 0, j = 0;
        unordered_map<char,int>mp2;
        while (j < m) {
            mp2[s2[j]]++;
            while(j-i+1>n){
                mp2[s2[i]]--;
                if(mp2[s2[i]]==0){
                    mp2.erase(s2[i]);
                }
                i++;
            }
            if(j-i+1==n){
                if(mp==mp2){
                    return true;
                }
            }
            j++;
        }
        return false;
    }
};