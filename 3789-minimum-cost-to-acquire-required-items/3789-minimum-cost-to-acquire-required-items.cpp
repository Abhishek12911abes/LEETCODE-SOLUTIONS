class Solution {
public:
    typedef long long ll;
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(need1==0 && need2==0){
            return 0;
        }
        ll type1=1LL*need1*cost1;
        ll type2=1LL*need2*cost2;
        ll total=1LL*type1+type2;
        ll mini=min(need1,need2);
        ll maxi=max(need1,need2);
        ll type3=1LL*maxi*costBoth;
        ll type4=1LL*mini*costBoth;
        if(need1>mini){
            type4+=(need1-mini)*cost1;
        }
        else{
            type4+=(need2-mini)*cost2;
        }
        return min({total,type3,type4});
        
        
    }
};