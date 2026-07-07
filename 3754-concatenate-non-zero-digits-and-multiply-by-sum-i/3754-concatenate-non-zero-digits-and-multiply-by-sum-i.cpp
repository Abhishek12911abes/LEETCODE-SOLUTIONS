class Solution {
public:
    #define ll long long
    long long sumAndMultiply(int n) {
        ll digitSum=0;
        string s;
        while(n>0){
            if(n%10!=0){
                s+=(n%10)+'0';
            }
            digitSum+=n%10;
            n/=10;
        }
        reverse(begin(s),end(s));
        ll num;
        if(!s.empty()){
            num=stoll(s);
        }
        return 1LL*num*digitSum;
    }
};