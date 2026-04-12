class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(); 
        
        vector <int> left(n, 1); // product of all elements 0-i except i 
        vector <int> right(n, 1); // product of all elements from i - n except i 
        
        int prod = 1 * nums[0];  
        for (int i = 1; i < n; i++) {
            left[i] = prod; 
            prod *= nums[i]; 
        }

        prod = 1; 
        for (int i = n - 1; i >= 0; i--) {
            right[i] = prod; 
            prod *= nums[i]; 
        }

        vector<int> res(n); 

        for (int i = 0; i < n; i++) {
            cout << left[i] << " " << right[i] << "\n"; 
            res[i] = left[i] * right[i]; 
        }

        for (auto x: res) cout << x << " "; 
        return res; 
    }
};
