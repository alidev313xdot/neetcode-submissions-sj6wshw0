class Solution {
public:
    int trap(vector<int>& height) {
        // for each index find how many water can it hold 
        // to find the amount of water that each index i can hold, find the 
        // left maximum and right maximum boundries of the each index  i 
        // the amount of water it can hold will be min(L, R) - H[i]

        int n = height.size(); 
        vector<int> leftMax(n); 
        vector<int> rightMax(n); 

         
        for (int i = 1; i < n; i++) {
             leftMax[i] = max(leftMax[i - 1], height[i - 1]); 
             
        }

        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i + 1]); 
        }

        int water = 0; 
        for (int i = 0; i < n; i++) {
            int curr = min(leftMax[i], rightMax[i]) - height[i]; 
            water += curr > 0 ? curr : 0; 
        }
        return water; 
    }
};
