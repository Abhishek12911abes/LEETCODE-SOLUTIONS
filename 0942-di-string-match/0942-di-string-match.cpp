class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n=s.size();
        vector<int>ans;
        int i=0,j=n;
        int p=0;
        while(p<n){
            if(s[p]=='I'){
                ans.push_back(i);
                i++;
            }
            else{
                ans.push_back(j);
                j--;
            }
            p++;
        }
        if(s[n-1]=='I'){
            ans.push_back(i);
        }
        else{
            ans.push_back(j);
        }
        return ans;
        
    }
};