class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size(); 
        stack<pair<int, int>> st; // pair : [index, temp] 
        vector<int> res(n, 0); 

        for (int i = 0; i < n; i++) {
            int currTemp = temp[i]; 
            
            while (!st.empty() && currTemp > st.top().first) {
                auto [stackT, stackIdx] = st.top();
                st.pop();  
                res[stackIdx] = i - stackIdx; 
            }
            st.push({currTemp, i}); 
         }

         return res; 
    }
};
