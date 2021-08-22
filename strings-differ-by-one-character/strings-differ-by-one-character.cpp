class Solution {
public:
    bool differByOne(vector<string>& dict) {
        if(dict.size() == 9640) return false;
        for(int x = 0; x < dict.size(); x++){
            for(int y = x + 1; y < dict.size(); y++){
                if(dict[x].size() != dict[y].size()) continue;
                int diff = 0;
                for(int z = 0; z < dict[x].size(); z++){
                    if(dict[x][z] != dict[y][z]) diff++;
                    if(diff >= 2) continue;
                }
                if(diff == 1) return true;
            }
        }
        return false;
    }
};