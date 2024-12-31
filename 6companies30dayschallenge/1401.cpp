class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        if (xCenter < x2 && xCenter > x1 && yCenter < y2 && yCenter > y1) {
            return true;
        }
        if (((y1 <= yCenter + radius && y1 >= yCenter) || 
             (y2 >= yCenter - radius && y2 <= yCenter)) &&
            xCenter >= x1 && xCenter <= x2) {
            return true;
        }
        if (yCenter <= y2 && yCenter >= y1 && 
            ((xCenter - radius <= x2 && xCenter >= x2) || 
             (xCenter + radius >= x1 && xCenter <= x1))) {
            return true;
        }
        if (square(xCenter - x1) + square(yCenter - y1) <= square(radius) ||
            square(xCenter - x1) + square(yCenter - y2) <= square(radius) ||
            square(xCenter - x2) + square(yCenter - y1) <= square(radius) ||
            square(xCenter - x2) + square(yCenter - y2) <= square(radius)) {
            return true;
        }
        return false;
    }

private:
    int square(int n) {
        return n * n;
    }
};
