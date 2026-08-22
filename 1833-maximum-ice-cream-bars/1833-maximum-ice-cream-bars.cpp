class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n=costs.size();
        sort(begin(costs),end(costs));
        int count=0;
        for(int i=0;i<n;i++){
            coins-=costs[i];
            if(coins<0){
                break;
            }
            count++;
        }
        return count;
        
    }
};