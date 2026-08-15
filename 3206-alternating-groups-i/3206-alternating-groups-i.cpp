class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n=colors.size();
        int count=0;
        for(int i=0;i<n;i++){
            int prev=(i==0)?(colors[n-1]):colors[(i-1)%n];
            int curr=colors[i];
            int next=colors[(i+1)%n];
            if(prev!=curr && curr !=next){
                count++;
            }
        }
        return count;
        
    }
};