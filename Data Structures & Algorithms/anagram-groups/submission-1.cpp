class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size(); 
        unordered_map<string, vector<string>> mp; 
        vector<vector<string>> ans; 

        for (int i = 0; i < n; i++) {
            string s = strs[i]; 
            string sorted = s; 
            sort(sorted.begin(), sorted.end()); 
            
            mp[sorted].push_back(s); 
        }

        for (auto [k, anagrams]: mp) {
            ans.push_back(anagrams); 
        } 
        return ans; 
    }
};
