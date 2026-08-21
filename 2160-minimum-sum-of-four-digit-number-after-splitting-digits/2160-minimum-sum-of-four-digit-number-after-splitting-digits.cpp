class Solution {
public:
    int minimumSum(int num) {
       string s=to_string(num);
       sort(begin(s),end(s));
    //    cout<<s;
       int num1=(s[0]-'0')*10+(s[3]-'0');
       int num2=(s[1]-'0')*10+(s[2]-'0');
       return num1+num2;
        
    }
};