class Solution {
public:
    bool checkString(string s) {
        int n=s.size();
        int lasta=-1,firstb=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                lasta=i;
            }
            else if(s[i]=='b'){
                if(firstb==-1){
                    firstb=i;
                }
            }
        }
        if(firstb==-1 || lasta==-1){
            return true;
        }
        return lasta<firstb;
        
    }
};