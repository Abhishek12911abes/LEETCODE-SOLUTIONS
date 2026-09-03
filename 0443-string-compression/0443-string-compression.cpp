class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();

        int count=1;
        string ans;
        int i;
        for(i=1;i<n;i++){
            if(chars[i]!=chars[i-1]){
                ans+=chars[i-1];
                if(count>1){
                    ans+=to_string(count);
                }
                count=1;
            }
            else{
                count++;
            }
        }
        if(i==n){
            ans+=chars[n-1];
            if(count>1){
                ans+=to_string(count);
            }
        }
        for(int j = 0; j < ans.size(); j++) {
            chars[j] = ans[j];
        }
        return (int)ans.length();
        
    }
};