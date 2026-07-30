class Solution {
public:
    int addDigits(int num) {
        string temp=to_string(num);
        int sum;
        while(temp.size()>1){
            sum=0;
            while(num){
                sum+=num%10;
                num/=10;
            }
            num=sum;
            temp=to_string(num);
        }
        return num;
        
    }
};