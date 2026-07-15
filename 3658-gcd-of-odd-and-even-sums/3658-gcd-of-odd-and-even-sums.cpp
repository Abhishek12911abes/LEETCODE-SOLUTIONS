class Solution {
public:
    typedef long long int ll;
    int gcdOfOddEvenSums(int n) {
        ll oddSum=0;
        ll evenSum=0;
        int temp=n;
        ll i=1,j=2;
        while(temp){
            oddSum+=i;
            evenSum+=j;
            i+=2,j+=2;
            temp--;
            
        }
        return gcd(oddSum,evenSum);


    }
};