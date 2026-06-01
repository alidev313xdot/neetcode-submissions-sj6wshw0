class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       int m = s1.length(), n = s2.length();
       if (m > n) return false; 

       vector<int> count(26, 0); 

       // build freq difference table 
       for (int i = 0; i < m; i++) {
            count[s1[i] - 'a']--; 
            count[s2[i] - 'a']++;
       }

       int matches = 0; 
       for (int i = 0; i < 26; i++) {
            if (count[i] == 0) matches++; 
       }  

       if (matches == 26) return true; 

       // slide the window 
       for (int i = m; i < n; i++) {
            // add new char 
            int addIdx = s2[i] - 'a'; 
            if (count[addIdx] == 0) matches--; // lost the one match 
            count[addIdx]++; 
            if (count[addIdx] == 0) matches++; 

            // remove old char 
            int removeIdx = s2[i - m] - 'a'; 
            if (count[removeIdx] == 0) matches--; // lost the one match 
            count[removeIdx]--; 
            if (count[removeIdx] == 0) matches++; 

            if (matches == 26) return true; 
       }

       return false; 
    }
};