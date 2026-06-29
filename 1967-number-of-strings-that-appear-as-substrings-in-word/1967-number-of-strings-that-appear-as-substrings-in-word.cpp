class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n=word.size();
        unordered_set<string>st;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                string temp=word.substr(i,j-i+1);
                st.insert(temp);
            }
        }
        int count=0;
        for(string &pat : patterns){
            if(st.find(pat)!=st.end()){
                count++;
            }
        }
        return count;

        
    }
};