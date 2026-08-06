class Solution {
public:
    bool div(int i , int t){
        long long prod=1;
        while(i){
            prod*=i%10;
            i/=10;
        }
        return prod%t==0;
    }
    int smallestNumber(int n, int t) {
        for(int i=n;i<=100;i++){
            if(div(i,t)){
                return i;
            }
        }
        return -1;
        
    }
};