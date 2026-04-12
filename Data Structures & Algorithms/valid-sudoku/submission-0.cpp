class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row wise check 
        for (int i = 0; i < 9; i++) {
            unordered_set<char> st; 
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.' && st.count(board[i][j]) > 0) return false; 
                st.insert(board[i][j]); 
            }
        }
        // column wise check 
        for (int j = 0; j < 9; j++) {
            unordered_set<char> st; 
            for (int i = 0; i < 9; i++) {
                if (board[i][j] != '.' && st.count(board[i][j]) > 0) return false; 
                st.insert(board[i][j]); 
            }
        }
        // sub box wise check 
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                unordered_set<char> st; 
                for (int r = 0; r < 3; r++) {
                    for (int c = 0; c < 3; c++) {
                        if (board[i * 3 + r][j * 3 + c] != '.' && st.count(board[i * 3 + r][j * 3 + c]) > 0) return false; 
                        st.insert(board[i * 3 + r][j * 3 + c]); 
                    }
                }
            }
        }

        return true; 
    }
};
