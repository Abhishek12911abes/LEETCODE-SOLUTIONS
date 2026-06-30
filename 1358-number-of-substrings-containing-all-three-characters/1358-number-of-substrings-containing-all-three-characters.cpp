class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        long long count=0;
        int aCount=0,bCount=0,cCount=0;
        int i=0,j=0;
        while(j<n){
            if(s[j]=='a'){
                aCount++;
            }
            else if(s[j]=='b'){
                bCount++;
            }
            else if(s[j]=='c'){
                cCount++;
            }
            while(aCount>0 && bCount>0 && cCount>0){
                count+=n-j ;
                aCount-=s[i]=='a'; // left side se shrink kro
                bCount-=s[i]=='b';
                cCount-=s[i]=='c';
                i++;
            }
            j++;
        }
        return count;
        
    }
};