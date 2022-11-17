class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = (ax2-ax1) * (ay2-ay1);
        int area2 = (bx2-bx1) * (by2-by1);
        int comarea = 0;
        
        int left = max(ax1, bx1);
        int right = min(ax2, bx2);
        int top = min(ay2, by2);
        int bottom = max(ay1, by1);
        
        if(left < right && top > bottom)
            comarea = (right-left) *(top-bottom);
            
        return area1 + area2 - comarea;
    }
};

// distinct rectangles

// overlapping rectangles => find individual areas and subract overlap?
// one rectangle encloses other rectange, can this be captured by overlap?

// Area of Rectangle: abs(ax2-ax1)*abs(ay2-ay1)


// assuming first rectangle is to the left, and second to the right
// overlap:
// when s-x-start is < f-x-end and s-y-start < f-y-end
// or s-x-e < f-x-start and s-y-e < f-y-e
// 