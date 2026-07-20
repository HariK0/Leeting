class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        int total = rows * cols;

        k %= total;

        vector<vector<int>> result(rows, vector<int>(cols));

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                int current = r * cols + c;
                int shifted = (current + k) % total;

                int newRow = shifted / cols;
                int newCol = shifted % cols;

                result[newRow][newCol] = grid[r][c];
            }
        }

        return result;
    }
};