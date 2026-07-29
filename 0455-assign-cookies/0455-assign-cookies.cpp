class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();
        int m=s.size();

        sort(begin(g),end(g));
        sort(begin(s),end(s));

        int i=0,j=0;
        int count=0;
        while(i<n && j<m){
            if(g[i]<=s[j]){
                count++;
                j++,i++;
            }
            else{
                j++;
            }
        }
        return count;


        
    }
};