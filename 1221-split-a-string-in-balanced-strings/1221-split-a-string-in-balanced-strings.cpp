class Solution {
public:
    int balancedStringSplit(string s) {
        int sum=0;
        int count=0;
        for(char c : s){
            if(c=='R'){
                sum++;
            }
            else{
                sum--;
            }
            if(sum==0){
                count++;
            }
        }
        return count;
        
    }
};