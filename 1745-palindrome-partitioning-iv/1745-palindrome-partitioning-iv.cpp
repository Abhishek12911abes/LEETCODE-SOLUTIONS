class Solution {
public:
    bool checkPartitioning(string s) {
        int n=s.size();

        // pehle 2d dp table banao for checking s[i...j] Palindrome hai ki nhi

        vector<vector<bool>>dp(n,vector<bool>(n));

        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        
        for(int L=2;L<=n;L++){
            for(int i=0;i+L-1<n;i++){
                int j=i+L-1;
                if(L==2){
                    dp[i][j]=(s[i]==s[j]);
                }
                else{
                    dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]);
                }
            }   
        }

        // ab check kro ki kya mai 3 parts (2 cuts) me s ko palindrome bana skta hu ki nhi
 
        for(int i=0;i<n-2;i++){// i first cut ki position hai.
        // i < n-2 isliye taki first cut ke baad kam se kam 2 characters
        // bache, jisse second aur third part non-empty ban sake. eg aba | b  | d 

            if(!dp[0][i]) continue; // maan ke chalo pehla part hi pal nhi hai toh cut kahi aur aage lagao

            for(int j=i+1;j<n-1;j++){

                if(dp[i+1][j] && dp[j+1][n-1]){
                    return true;
                }
            }
        }
        return false;

        
    }
};