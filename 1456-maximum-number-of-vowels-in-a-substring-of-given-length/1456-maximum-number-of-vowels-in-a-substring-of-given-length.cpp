class Solution {
public:
    bool isVowel(char &ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    int maxVowels(string s, int k) {    
        int n=s.size();
        int maxVowel=0;
        int count=0;
        int i=0,j=0;
        while(j<n){
            if(isVowel(s[j])){
               count++;
            }
            if(j-i+1>k){
                if(isVowel(s[i])){
                    count--;
                }
                i++;
            }
            if(j-i+1==k){
                maxVowel=max(maxVowel,count);
            }
            j++;
        }
        return maxVowel;

        
    }
};