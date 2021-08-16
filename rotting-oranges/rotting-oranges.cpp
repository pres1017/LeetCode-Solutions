class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // first run-through will find all rotting oranges, second run-through will confirm all rotting oranges were caught
        queue<vector<int>> rot;
        for(int row = 0; row < grid.size(); row++){
            for(int col = 0; col < grid[row].size(); col++){
                if(grid[row][col] == 2){
                    vector<int> toPush;
                    toPush.push_back(row); toPush.push_back(col);
                    rot.push(toPush);
                }
            }
        }
        int time = 0;
        queue<vector<int>> futureRot;
        vector<int> temp; temp.push_back(-1); temp.push_back(-1);
        futureRot.push(temp); // to stop infinite while loop
        int count = 0;
        while(futureRot.size() > 0){
            futureRot.pop(); // pops the {-1, -1}
            for(auto row : grid){
                for(auto col : row){
                    std::cout << col << " ";
                }
                std::cout << "\n";
            }
            std::cout << time << "\n\n";
            while(rot.size() > 0){
                int row = rot.front()[0];
                int col = rot.front()[1];
                std::cout << "ROW: " << row << " COL: " << col << "\n";
                rot.pop();
                if(row - 1 >= 0 && grid[row - 1][col] == 1){
                    grid[row - 1][col] = 2;
                    vector<int> temp; temp.push_back(row - 1); temp.push_back(col);
                    futureRot.push(temp);
                }
                if(row + 1 < grid.size() && grid[row + 1][col] == 1){
                    grid[row+1][col] = 2;
                    vector<int> temp; temp.push_back(row + 1); temp.push_back(col);
                    futureRot.push(temp);
                }
                if(col - 1 >= 0 && grid[row][col - 1] == 1){
                    grid[row][col-1] = 2;
                    vector<int> temp; temp.push_back(row); temp.push_back(col-1);
                    futureRot.push(temp);
                }
                if(col + 1 < grid[row].size() && grid[row][col + 1] == 1){
                    grid[row][col+1]=2;
                    vector<int> temp; temp.push_back(row); temp.push_back(col+1);
                    futureRot.push(temp);
                }
            }
            if(futureRot.size() > 0){
                time++;
                while(futureRot.size() > 0){
                    rot.push(futureRot.front());
                    futureRot.pop();
                }
                vector<int> temp; temp.push_back(-1); temp.push_back(-1);
                futureRot.push(temp);
            }
        }
        for(int row = 0; row < grid.size(); row++){
            for(int col = 0; col < grid[row].size(); col++){
                if(grid[row][col] == 1){
                    return -1;
                }
            }
        }
        return time;
    }
};