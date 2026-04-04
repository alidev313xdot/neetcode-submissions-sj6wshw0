class Solution {
public:
    int characterReplacement(string s, int k) {
      int n = s.length(); 
      int ans = 0; 
      
      unordered_map<char, int> mp; 

      int i = 0; 
      int j = 0; 
      int mxFreq = 0; 

      while (j < n) {
        mp[s[j]]++; 
        mxFreq = max(mxFreq, mp[s[j]]); 


        while ( j - i + 1 - mxFreq > k) {
            // shrink the window 
            mp[s[i]]--; 
            i++; 
        } 

        // window is valid save its length 
        ans = max(ans, j - i + 1);
        j++;  
      }   
      return ans; 
    }
};