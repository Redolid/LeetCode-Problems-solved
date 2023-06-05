class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        
        // If there are only two points, they will always form a straight line.
        if (n <= 2) {
            return true;
        }
        
        // Calculate the slope of the first two points.
        int x0 = coordinates[0][0];
        int y0 = coordinates[0][1];
        int x1 = coordinates[1][0];
        int y1 = coordinates[1][1];
        int dx = x1 - x0;
        int dy = y1 - y0;
        
        // Check if all the other points have the same slope with respect to the first two points.
        for (int i = 2; i < n; i++) {
            int x = coordinates[i][0];
            int y = coordinates[i][1];
            
            // If the current point does not have the same slope, return false.
            if (dx * (y - y1) != dy * (x - x1)) {
                return false;
            }
        }
        
        return true;
    }
};
