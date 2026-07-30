class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();

        int count=1,val=1;
        int ans=0;
        for(char ch : word){
            ans+=val;
            if(count%8==0){
                val++;
            }
            count++;
        }
        return ans;
        
    }
};