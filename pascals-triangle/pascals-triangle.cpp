class Solution {
public:
    void genRow(vector<vector<int>>& triangle){
        vector<int> prevRow = triangle[triangle.size() - 1];
        vector<int> newRow;
        for(int x = 0; x <= prevRow.size(); x++){
            if(x == 0 || x == prevRow.size()) newRow.push_back(1);
            else{
                newRow.push_back(prevRow[x] + prevRow[x - 1]);
            }
        }
        triangle.push_back(newRow);
    }
    
    vector<vector<int>> generate(int numRows) {
        int curRow = 1;
        vector<vector<int>> solution(1, vector<int>(1, 1));
        while(curRow < numRows){
            genRow(solution);
            curRow++;
        }
        return solution;
    }
};