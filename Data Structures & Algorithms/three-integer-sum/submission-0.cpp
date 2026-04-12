class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        vector<vector<int>> ans; 
        int n = nums.size(); 

        for (int i = 0; i <= n - 3; i++) {
            int a = nums[i]; 
            if (i > 0 && a == nums[i - 1]) continue; // skip the dupliacate  a 
            int l = i + 1, r = n - 1;
             while (l < r) {
                    long long sum = (long long) nums[i] +  nums[l] + nums[r]; 
                    if ( sum == 0) {
                        ans.push_back({nums[i], nums[l],  nums[r]}); 

                        while (l < r && nums[l + 1] == nums[l]) l++; 
                        while (l < r && nums[r - 1] == nums[r]) r--;
                          
                        l++; 
                        r--; 
                    }
                    else if (sum < 0) l++; 
                    else r--; 
                }
        }

        return ans; 
    }
};




// [-1,0,1,2,-1,-4]
// sort = [-4, -1, -1, 0, 1, 2]
//          i       l        r => -4 - 1 + 2 = -3 
//                     l     r => -4 + 0 + 2 = -2 
//                         l r => -4 + 1 + 2 = -1
//              i   l        r => -1 + -1 + 2 = 0 {-1, -1, 2} 
//                     l   r   => -1 + 0 + 1  = 0 {-1, 0, 1} 
//                     i 











