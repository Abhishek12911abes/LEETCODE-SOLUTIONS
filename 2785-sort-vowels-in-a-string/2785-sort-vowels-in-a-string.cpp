class Solution {
public:
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I'
            || c== 'O' || c=='U';
    }
    string sortVowels(string s) {
        int n=s.size();
        string temp=s;
        string vowel;
        string org;
        for(char c : temp){
            if(isVowel(c)){
                vowel+=c;
                org+='#';
            }
            else{
                org+=c;
            }
        }
        sort(begin(vowel),end(vowel));
        cout<<vowel;
        cout<<org;

        int i=0;
        string ans;
        for(char c : org){
            if(c=='#'){
                ans+=vowel[i];
                i++;
            }
            else{
                ans+=c;
            }
        }
        return ans;
        
    }
};