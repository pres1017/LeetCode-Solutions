class Solution {
public:
    void dfs(vector<vector<int>>& cities, vector<bool>& visits, int city){
        if(visits[city] == true) return;
        visits[city] = true;
        for(int x = 0; x < cities[city].size(); x++){
            if(cities[city][x] == 1) dfs(cities, visits, x);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int numProvinces = 0;
        vector<bool> hasVisited(isConnected.size(), false);
        for(int x = 0; x < hasVisited.size(); x++){
            if(!hasVisited[x]){
                numProvinces++;
                dfs(isConnected, hasVisited, x);
            }
        }
        return numProvinces;
    }
};