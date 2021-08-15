class Solution {
public:
    bool isRobotBounded(string instructions) {
        int direction = 0;
        int x = 0;
        int y = 0;
        for(int i = 0; i < 4; i++){
            for(auto instr : instructions){
                if(instr == 'L'){
                    if(direction == 0) direction = 3;
                    else direction -= 1;
                }
                
                else if(instr == 'R'){
                    if(direction == 3) direction = 0;
                    else direction += 1;
                }
                else{
                    if(direction == 0) y += 1;
                    else if(direction == 1) x -= 1;
                    else if(direction == 2) y -= 1;
                    else x += 1;
                }
            }
            if(x == 0 && y == 0) return true;
        }
        return false;
    }
};