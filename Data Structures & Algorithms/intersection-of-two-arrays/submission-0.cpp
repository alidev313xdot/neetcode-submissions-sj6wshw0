class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Opitimized Set methods using single set 
        vector<int> res; 
        set<int> st(nums1.begin(), nums1.end()); 
        
        for (auto x: nums2) {
           if (st.count(x) > 0){
               res.push_back(x); 
               st.erase(x); 
           } 
        }

        return res; 
    }
};