class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size(); 
        unordered_map<int, int> freq; 

        for (auto x: nums) freq[x]++; 

        vector<vector<int>> bucket (n + 1); // each ith bucket store all elements having freq = i  
        for (auto [x, f]: freq) {
            bucket[f].push_back(x); 
        }

        // The bucket at the last index holds the most frequent element
        // so start collecting k elements from the end bucket, if it doesnt have enough k elements borrow from the adjacent bucket 
        vector<int> res; 

        for (int f = n; f >= 1; f--) {
            for (auto x: bucket[f]) {
                if (res.size() == k) return res; 
                res.push_back(x); 
            } 
        } 

        return res; 
    }
};
