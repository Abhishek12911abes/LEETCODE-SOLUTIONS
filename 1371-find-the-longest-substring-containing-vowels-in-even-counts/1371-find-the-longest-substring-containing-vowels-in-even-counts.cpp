class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n=s.size();
        int result=0;
        unordered_map<string,int>mp;
        string curr="00000";
        mp[curr]=-1; // ye wala curr state maine pehli baar -1 pe dekha haai

        vector<int>vowelCount(5,0);

        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                vowelCount[0]=(vowelCount[0]+1)%2;
            }
            else if(s[i]=='e'){
                vowelCount[1]=(vowelCount[1]+1)%2;
            }
            else if(s[i]=='i'){
                vowelCount[2]=(vowelCount[2]+1)%2;
            }
            else if(s[i]=='o'){
                vowelCount[3]=(vowelCount[3]+1)%2;
            }
            else if(s[i]=='u'){
                vowelCount[4]=(vowelCount[4]+1)%2;
            }

            curr="";
            for(int j=0;j<5;j++){
                curr+=to_string(vowelCount[j]);
            }

            if(mp.count(curr)){
                result=max(result,i-mp[curr]);
            }
            else{
                mp[curr]=i;
            }
        }
        return result;
        
    }
};