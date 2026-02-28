#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        
        vector<int> freq(26, 0);   // O(26)
        
        // Count frequency
        for(char &ch : s){        // O(n)
            freq[ch - 'a']++;
        }
        
        // Max heap of characters
        priority_queue<char> pq;
        
        for(int i = 0; i < 26; i++){
            if(freq[i] > 0){
                pq.push(i + 'a');
            }
        }
        
        string result;
        
        while(!pq.empty()){
            
            char ch = pq.top();
            pq.pop();
            
            int fq = min(freq[ch - 'a'], repeatLimit);
            
            // Add ch up to repeatLimit times
            result.append(fq, ch);
            freq[ch - 'a'] -= fq;
            
            // If still remaining and we need a breaker
            if(freq[ch - 'a'] > 0){
                
                if(pq.empty()) break;
                
                char nextChar = pq.top();
                pq.pop();
                
                result.push_back(nextChar);
                freq[nextChar - 'a']--;
                
                if(freq[nextChar - 'a'] > 0){
                    pq.push(nextChar);
                }
                
                // Push current character back
                pq.push(ch);
            }
        }
        
        return result;
    }
};

int main() {
    
    Solution obj;
    
    string s;
    int repeatLimit;
    
    cout << "Enter string: ";
    cin >> s;
    
    cout << "Enter repeatLimit: ";
    cin >> repeatLimit;
    
    string ans = obj.repeatLimitedString(s, repeatLimit);
    
    cout << "Result: " << ans << endl;
    
    return 0;
}