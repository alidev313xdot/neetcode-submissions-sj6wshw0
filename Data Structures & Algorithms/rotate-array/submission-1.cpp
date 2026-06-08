class Solution {
public:
    void reverse(vector<int>& nums, int start,int end) {
        while (start <= end) {
            swap(nums[start], nums[end]); 
            start++;
            end--; 
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(); 
        k = k % n; 
        
        // 1. reverse whole array 
        reverse(nums, 0, n - 1); 

        // 2. Reverse first k elements 
        reverse(nums, 0, k - 1); 

        // reverse remaining elements from k to n - 1 
        reverse(nums, k, n - 1); 
    }
};