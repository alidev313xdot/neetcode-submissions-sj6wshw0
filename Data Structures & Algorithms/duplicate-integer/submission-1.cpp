class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> st; 
        for (auto x: nums) st.insert(x); 

        return nums.size() > st.size(); 
    }
};