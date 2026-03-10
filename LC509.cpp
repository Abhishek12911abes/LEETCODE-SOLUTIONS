#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int>& dp){

    // base case
    if(n<=1)
        return n;

    // agar pehle se calculated hai
    if(dp[n] != -1)
        return dp[n];

    // store the result
    dp[n] = solve(n-1, dp) + solve(n-2, dp);

    return dp[n];
}

int main(){

    int n;
    cin >> n;

    vector<int> dp(n+1, -1);

    cout << solve(n, dp);

    return 0;
}