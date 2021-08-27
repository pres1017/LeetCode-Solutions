class Solution {
public:
    vector<vector<int>> toReturn;
    
    void recPerm(vector<int> curArray, vector<int> nums){
        if(nums.size() == 0){
            this->toReturn.push_back(curArray);
        }
        for(int x = 0; x < nums.size(); x++){
            vector<int> tempNums = nums;
            vector<int> tempArray = curArray;
            tempNums.erase(tempNums.begin() + x);
            tempArray.push_back(nums[x]);
            recPerm(tempArray, tempNums);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        toReturn = vector<vector<int>>();
        recPerm(vector<int>(), nums);
        return toReturn;
    }
};