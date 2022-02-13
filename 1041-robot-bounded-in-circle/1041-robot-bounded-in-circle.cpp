class Solution {
public:
    void set_direction(int &dir, char move) {
        if(move == 'R') {
            dir = (dir+1)%4;
        }
        else dir = (dir+3)%4;
    }

    bool isRobotBounded(string instructions) {
        int x=0, y=0;
        int move[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir = 0; // Starts north
        for(char c: instructions) {
            if(c == 'G') {
                x += move[dir][0];
                y += move[dir][1];
            } else set_direction(dir, c);
        }            
        return (x==0 && y==0) || (dir != 0);
    }
};