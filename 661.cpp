class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int rows = img.size();          // Number of rows
        int cols = img[0].size();       // Number of columns
        
        // Initialize the result matrix with the same dimensions
        vector<vector<int>> result(rows, vector<int>(cols, 0));
        
        // Directions array for traversing neighbors (row and column offsets)
        vector<pair<int, int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1},  // Top-left, Top, Top-right
            { 0, -1}, { 0, 0}, { 0, 1},  // Left, Center, Right
            { 1, -1}, { 1, 0}, { 1, 1}   // Bottom-left, Bottom, Bottom-right
        };
        
        // Traverse each cell in the matrix
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int sum = 0;   // Initialize sum of values
                int count = 0; // Count of valid neighbors
                
                // Check all neighbors (including the current cell)
                for (auto& dir : directions) {
                    int x = i + dir.first;  // New row index
                    int y = j + dir.second; // New column index
                    
                    // Check if the neighbor is within bounds
                    if (x >= 0 && x < rows && y >= 0 && y < cols) {
                        sum += img[x][y];  // Add the neighbor's value
                        count++;           // Increment the count of valid cells
                    }
                }
                
                // Compute the smoothed value by flooring the average
                result[i][j] = floor(sum / count);
            }
        }
        
        return result; // Return the smoothed image
        
    }
};