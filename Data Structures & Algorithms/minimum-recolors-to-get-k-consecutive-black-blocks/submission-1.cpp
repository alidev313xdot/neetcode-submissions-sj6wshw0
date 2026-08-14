class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length(); 
        int count = 0; // white blocks count 

        for (int i = 0; i < k; i++) count += blocks[i] == 'W'; 
        int res = count; 

        for (int i = k; i < n; i++) {
            count -= blocks[i - k] == 'W'; 
            count += blocks[i] == 'W'; 

            res = min(res, count);
        }

        return res; 
    }
};