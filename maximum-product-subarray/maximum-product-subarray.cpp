class Solution {
public:
    // partition based on zeros
    
    int maxProduct(vector<int>& nums) {
        int absMax = nums[0]; 
        int absMin = nums[0];
        int oldMax = absMax;
        for(int i = 1; i < nums.size(); i++){
            std::cout << absMax << " " << absMin << "\n";
            int tempMax = max(nums[i], max(absMax * nums[i], absMin * nums[i]));
            
            absMin = min(nums[i], min(absMax * nums[i], absMin * nums[i]));
            absMax = tempMax;
            
            oldMax = max(oldMax, absMax); 
        }
        return oldMax;
    }
};