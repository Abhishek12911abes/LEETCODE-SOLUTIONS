class Solution {
public:
    bool checkDivisibility(int n) {
        int temp=n;
        int digitSum=0;
        int digitProduct=1;
        while(n!=0){
            int digit=n%10;
            digitSum+=digit;
            digitProduct*=digit;
            n/=10;
        }
        int totalSum=digitSum+digitProduct;
        return (temp%totalSum==0);
    }
};