class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int n=s.size();
        int m=spaces.size();
        int i=0,j=0; 
        int count=0;
        while(i<n && j<m){
            if(count==spaces[j]){
                ans+=' ';
                j++;
            }
            ans+=s[i];
            i++,count++;
        }
        while(i<n){
            ans+=s[i];
            i++;
        }
        return ans;
        
    }
};