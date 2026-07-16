class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size();
        int n=t.size();

        unordered_map<int,int> mp; // isme ham t ke saare char ko store krenge

        for(char c : t){
            mp[c]++;
        }
        int totalCharReq=n;

        int i=0,j=0;
        int start_i=-1;
        int minLen=INT_MAX;
        while(j<m){
            if(mp[s[j]]>0){ // matlab ki wo char t me tha aur minus krne ke baad bhi uski freq > 0 hai
                totalCharReq--;
            }
            mp[s[j]]--;
            while(totalCharReq==0){
                if(j-i+1<minLen){
                    minLen=j-i+1;
                    start_i=i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0){
                    totalCharReq++;
                }
                i++;
            }
            j++;
        }
        return minLen==INT_MAX?"":s.substr(start_i,minLen);

        
    }
};