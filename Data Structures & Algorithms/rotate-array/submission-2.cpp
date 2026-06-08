class Solution {
public:
    // Approach two using formula new_pos = (i + k) % n 
    // for example i = 0, n = 4, k = 3 
    // so position of this first element after k rotations will be 
    // (i + k) % n = (0 + 3) % 4 = 3 
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(); 
        k = k % n; 
        vector<int> temp(n, 0); 

        for (int i = 0; i < n; i++) {
            temp[(i + k) % n] = nums[i];
        }

        nums = temp; 
    }
};