int minimumArea(vector<vector<int>>& grid) 
{
        int minRow = 1001;
        int maxRow = 0;
        int minCol = 1001;
        int maxCol = 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < cols; ++j) 
            {
                if (grid[i][j] == 1) 
                {
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }
        
        int height = maxRow - minRow + 1;
        int width = maxCol - minCol + 1;
        
        return height * width;
}
