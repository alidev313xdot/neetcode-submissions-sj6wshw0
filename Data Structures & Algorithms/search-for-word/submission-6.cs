public class Solution {
    public bool Exist(char[][] board, string word) {
        int rows = board.Length; 
        int cols = board[0].Length; 

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                // find the first matching characte 
               if (dfs(board, word, r, c, 0)) {
                    return true; 
               }
            }
        }
        // While you have checked every possible path, but coudn't find the word return false 
        return false; 
    }

    private bool dfs(char[][] board, string word, int r, int c, int index) {
        if (index == word.Length) return true; // found the whole word 

        // out of bounds or letter doesnt match the current letter of the word 
        if (r < 0 || c < 0 || r >= board.Length || c >= board[0].Length || board[r][c] != word[index])  {
            return false; 
        }

        // mark this cell as visited to avoid revisitng 
        char temp = board[r][c]; 
        board[r][c] = '#'; 

        // Explore all 4 directions for the next character 
        bool found = dfs(board, word, r + 1, c, index + 1) || 
                     dfs(board, word, r - 1, c, index + 1) || 
                     dfs(board, word, r, c + 1, index + 1) || 
                     dfs(board, word, r, c - 1, index + 1); 

        // Restore the current cell and back track 
        board[r][c] = temp; 

        return found; 
    }
}
