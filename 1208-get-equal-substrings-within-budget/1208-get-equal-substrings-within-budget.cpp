class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size();
        int maxLen=0;
        int i=0,j=0;
        int cost=0;
        while(j<n){
            int diff=abs((int)(s[j]-t[j]));
            cost=cost+diff;
            while(cost>maxCost){
                diff=abs((int)(s[i]-t[i]));
                cost-=diff;
                i++;
            }
            if(cost<=maxCost){
                maxLen=max(maxLen,j-i+1);
            }
            j++;
        }
        return maxLen;
        
    }
};