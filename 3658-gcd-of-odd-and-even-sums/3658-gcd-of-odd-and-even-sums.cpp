class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddSum=0;
        int evenSum=0;
        int temp=n;
        int i=1,j=2;
        while(temp){
            oddSum+=i;
            evenSum+=j;
            i+=2,j+=2;
            temp--;
            
        }
        return gcd(oddSum,evenSum);


    }
};