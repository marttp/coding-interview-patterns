#include <vector>
#include <algorithm>

int largestSquareInAMatrixOptimized(std::vector<std::vector<int>>& matrix) {
    if (matrix.empty()) {
        return 0;
    }
    int m = matrix.size();
    int n = matrix[0].size();
    std::vector<int> prevRow(n, 0);
    int maxLen = 0;
    // Iterate through the matrix.
    for (int i = 0; i < m; i++) {
        std::vector<int> currRow(n, 0);
        for (int j = 0; j < n; j++) {
            // Base cases: if we’re in row 0 or column 0, the largest square ending
            // here has a length of 1. This can be set by using the value in the
            // input matrix.
            if (i == 0 || j == 0) {
                currRow[j] = matrix[i][j];
            } else {
                if (matrix[i][j] == 1) {
                    // currRow[j] = 1 + min(left, top-left, top)
                    currRow[j] = 1 + std::min({currRow[j - 1], prevRow[j - 1], prevRow[j]});
                }
            }
            maxLen = std::max(maxLen, currRow[j]);
        }
        // Update 'prevRow' with 'currRow' values for the next iteration.
        prevRow = currRow;
    }
    return maxLen * maxLen;
}