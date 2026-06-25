class Solution {
public:
    int findClosest(int x, int y, int z) {
        
        int person1Speed=abs(x-z);
        int person2Speed=abs(y-z);

        int mini=min(person1Speed,person2Speed);
        if(mini==person1Speed && mini==person2Speed){
            return 0;
        }
        if(mini==person1Speed){
            return 1;
        }
        return 2;

    }
};