class Solution {
public:
    int minPartitions(string n) {
        char maxi = *max_element(begin(n),end(n));
        return maxi-'0';
    }
};