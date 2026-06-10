class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(); 
        unordered_map<int, int> freq; 

        for (auto x: nums) {
            freq[x]++; 
        }

        vector<int> ans; 

        for (auto [x, f] : freq) {
            if (f > n / 3) ans.push_back(x); 
        }

        return ans; 
    }
};