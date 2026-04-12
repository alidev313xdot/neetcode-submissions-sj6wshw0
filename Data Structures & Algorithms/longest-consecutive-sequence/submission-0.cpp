class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> st(nums.begin(), nums.end());

        for (int num : nums) {
            int length = 0, curr = num;
            while (st.find(curr) != st.end()) {
                length++;
                curr++;
            }
            res = max(res, length);
        }
        return res;
    }
};