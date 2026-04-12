class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size(); 
        unordered_map<int, int> freq; 

        for (int i = 0; i < n; i++) {
            freq[nums[i]]++; 
        }

        vector<vector<int>> numFreq; 
        for (auto [x, f]: freq) {
            numFreq.push_back({x, f}); 
        }

        sort(numFreq.begin(), numFreq.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] > b[1]; // sort in descending frequiency  
        }); 

        vector<int> res; 
        for (int i = 0; i < k; i++) {
            res.push_back(numFreq[i][0]); 
        }
        return res; 
    }
};
