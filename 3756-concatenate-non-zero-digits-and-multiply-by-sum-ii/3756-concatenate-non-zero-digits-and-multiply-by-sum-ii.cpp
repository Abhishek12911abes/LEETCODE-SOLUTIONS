class Solution {
public:

    typedef long long ll;
    int mod=1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size();
        int q=queries.size();

        vector<ll>pow10(n+1,0);
        vector<ll>digitSum(n,0);
        vector<ll>numberUpTo(n,0); // ye har 0 se i tak ka number generate krega 
        vector<ll>nonZero(n,0); // ye har 0 se i  tak ke beech ka nonzero no generate krega
        pow10[0]=1;

        for(int i=1;i<=n;i++){
            pow10[i]=(pow10[i-1]*10)%mod;
        }
        digitSum[0]=s[0]-'0';
        for (int i = 1; i < n; i++) {
            digitSum[i] = (digitSum[i - 1] + (s[i] - '0')) % mod;
        }
        numberUpTo[0]=s[0]-'0';
        for(int i=1;i<n;i++){
            int digit=s[i]-'0';
            if(digit!=0){
                numberUpTo[i] = (numberUpTo[i - 1] * 10 + digit) % mod;
            }
            else{
                numberUpTo[i]=numberUpTo[i-1];
            }
        }
        nonZero[0]=s[0]!='0'?1:0; 
        for(int i=1;i<n;i++){
            int digit=s[i]-'0';
            if(s[i]!='0'){
                nonZero[i] = nonZero[i - 1] + 1;
            }
            else{
                nonZero[i]=nonZero[i-1];
            }
        } 
        vector<int>result(q);
        for(int i=0;i<q;i++){
            int l=queries[i][0];
            int r=queries[i][1];

            ll sum=digitSum[r]-((l==0)?0:digitSum[l-1]);

            int k=nonZero[r]-((l==0)?0:nonZero[l-1]);

            ll leftValue = (l == 0) ? 0 : numberUpTo[l - 1];

            ll x=(numberUpTo[r]-(leftValue*pow10[k]%mod)+mod)%mod;

            result[i] = (int)((sum * x) % mod);
        }   
        return result;   
    }
};