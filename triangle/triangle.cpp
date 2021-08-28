class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> newTriangle;
        newTriangle.push_back(vector<int>());
        newTriangle[0].push_back(triangle[0][0]);
        int row = 1;
        while(row < triangle.size()){
            vector<int> tempRow;
            for(int i = 0; i < triangle[row].size(); i++){
                if(i == 0) 
                    tempRow.push_back(triangle[row][0] + newTriangle[row - 1][0]);
                else if(i == triangle[row].size() - 1) 
                    tempRow.push_back(triangle[row][i] + newTriangle[row - 1][i - 1]);
                else{
                    tempRow.push_back(min(newTriangle[row - 1][i], newTriangle[row - 1][i - 1]) + triangle[row][i]);
                }
            }
            newTriangle.push_back(tempRow);
            row++;
        }
        int minVal = newTriangle[newTriangle.size() - 1][0];
        /*
        for(int x = 0; x < newTriangle.size(); x++){
            for(int y = 0; y < newTriangle[x].size(); y++){
                std::cout << newTriangle[x][y] << " ";
            }
            std::cout << "\n";
        }
        */
        for(auto val : newTriangle[newTriangle.size() - 1]){
            minVal = min(minVal, val);
        }
        return minVal;
    }
};