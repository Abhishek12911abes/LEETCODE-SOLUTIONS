class Solution {
public:
    // int t[2001][2001]; // n^2 states // TLE - 32/37
    // // TC = O(n^2 * O(n+n)) ~ O(n^3)
    // bool isPalindrome(string& s, int i, int j) {
    //     while(i < j) {
    //         if(s[i] != s[j])
    //             return false;
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }
    // int solve(string& s, int i, int j) {
    //     if(i >= j)
    //         return 0;
    //     if(t[i][j] != -1)
    //         return t[i][j];
        
    //     if(isPalindrome(s, i, j)) // O(n)
    //         return t[i][j] = 0;
        
    //     int part = INT_MAX;
    //     for(int k = i; k<=j-1; k++) { // O(n)
    //         int temp = 1 + solve(s, i, k) + solve(s, k+1, j);
            
    //         part = min(part, temp);
    //     }
        
    //     return t[i][j] = part;
    // }
    int minCut(string s) {
        int n = s.length();
        // memset(t, -1, sizeof(t));
        // return solve(s, 0, n-1);

        // Pehle ham log Blueprint wale code se dp table bhar lete hai jisse ham wo ye bata dega ki s[0...i] palindrome hai ki nhi

        vector<vector<bool>>dp(n,vector<bool>(n,false));

        for(int i=0;i<n;i++){
            dp[i][i]=true; // diagonal elem ie 1 size ka char hamesha palindrome hota hai;
        }

        for(int L=2;L<=n;L++){
            for(int i=0;i+L-1<n;i++){
                int j=i+L-1;
                if(L==2){
                    dp[i][j]=s[i]==s[j];
                }
                else{
                    dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]);
                }
            }
        } 

        vector<int>t(n); 
        // dp[i]=min cuts required to cut a string s[0...i] into palindromes

        for(int i=0;i<n;i++){
            if(dp[0][i]==true){ //s[0..i] is a plaindrome
                t[i]=0; // no cuts required
            }
            else{
                t[i]=INT_MAX;
                for(int k=0;k<i;k++) {// har index pe try kro
                    if(dp[k+1][i]==true && 1+t[k]<t[i]){
                        t[i]=1+t[k];
                    }
                }
            }
        }
        return t[n-1]; // ye store krega s[0...i] me total kitne min cuts lage for palindrome

    }
};