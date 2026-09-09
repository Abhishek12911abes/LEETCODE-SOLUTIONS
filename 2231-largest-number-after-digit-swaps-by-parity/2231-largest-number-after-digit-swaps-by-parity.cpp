class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int>even,odd;

        int temp=num;
        while(temp){
            int lastDigit=temp%10;
            if(lastDigit%2==0){
                even.push(lastDigit);
            }
            else{
                odd.push(lastDigit);
            }
            temp/=10;
        }
        string s=to_string(num);
        
        long long ans=0;

        for(int i=0;i<s.size();i++){
            int d=s[i]-'0';
            if(d%2==0){
                int e=even.top();
                even.pop();
                ans=ans*10+e;
            }
            else{
                int o=odd.top();
                odd.pop();
                ans=ans*10+o;
            }
        }
        return ans;
        
    }
};