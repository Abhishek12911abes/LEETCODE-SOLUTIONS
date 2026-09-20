class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        for(int i=0;i<s.size();i++){
            int revIdx=int('z'-s[i]+1);
            int prod=revIdx*(i+1);
            cout<<prod;
            sum+=prod;
        }
        return sum;
        
    }
};