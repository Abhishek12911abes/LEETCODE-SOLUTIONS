class Solution {
public:
    long long minimumSteps(string s) {
        int n=s.size();
        int oneCount=0;
        long long swaps1=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                oneCount++;
            }
            else{
                swaps1+=oneCount;
            }
        }
        int zeroCount=0;
        long long swaps2=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                zeroCount++;
            }
            else{
                swaps2+=zeroCount;
            }
        }
        return min(swaps1,swaps2);
    }
};