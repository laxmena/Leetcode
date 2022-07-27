class Solution {
public:
    bool checkOverlap(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        bool overlap = true;
        if(!(((bx1 < ax2) && (bx1 > ax1)) ||
            ((bx2 < ax2) && (bx2 > ax1)) ||
            ((ax1 < bx2) && (ax1 > bx1)) ||
            ((ax2 < bx2) && (ax2 > bx1)) ||
            ((ax1 == bx1) && (ax2 == bx2))) ) {
            return false;
        } 
        
        if(!(((by1 < ay2) && (by1 > ay1)) ||
            ((by2 < ay2) && (by2 > ay1)) ||
            ((ay2 < by2) && (ay2 > by1)) ||
            ((ay1 < by2) && (ay1 > by1)) ||             
            ((ay1 == by1) && (ay2 == by2))) ) {
            return false;
        }   
        
        return true;
    }
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int cx1 = 0, cx2 = 0, cy1 = 0, cy2 = 0;
        if(checkOverlap(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2)) {
            cx1 = max(ax1, bx1);
            cx2 = min(ax2, bx2);
            cy1 = max(ay1, by1);
            cy2 = min(ay2, by2);    
            // cout << cx1 << " - " << cx2 << " | " << cy1 << " - " << cy2 << "\n";
        }
        
//         cout << "a: " << ax1 << ", " << ay1 << " | " << ax2 << ", " << ay2 << "\n";
//         cout << "b: " << bx1 << ", " << by1 << " | " << bx2 << ", " << by2 << "\n";
//         cout << "c: " << bx1 << ", " << cy1 << " | " << cx2 << ", " << cy2 << "\n";
        
        int area1 = abs(ax1-ax2)*abs(ay1-ay2);
        int area2 = abs(bx1-bx2)*abs(by1-by2);
        int area3 = abs(cx1-cx2)*abs(cy1-cy2);
            
        // cout << area1 << " " << area2 << " Overlap: " << area3 << "\n";
        
        return area1 + area2 - area3;
    }
};


// [[0,-1], [0, 2], [9, -1], [9, 2]]
// [[-3,0], [-3, 4], [3, 0], [3, 4]]


// ax1|2      bx1|2              
// [-3, 3] <=> [0, 9] Overlap x => [max(-3, 0), min(9, 3)] = [0, 3]
// ay1|2       by1|2              
// [0, 4] <=> [-1, 2] Overlap y => [max(-1, 0), min(2, 4)] = [0, 2]

// abs(ax1-ax2)*abs(ay1-ay2)
// 9*3 = 27
    
// b=> 6*4 => 24
    
// 3*2 = 6
    
// 24+21

// ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2