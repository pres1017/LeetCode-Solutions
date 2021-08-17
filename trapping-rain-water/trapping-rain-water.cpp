class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        vector<int> maxLeft(size, 0);
        vector<int> maxRight(size, 0);
        int left = height[0]; int right = height[height.size() - 1];
        int ptr1 = 0; int ptr2 = height.size() - 1;
        while(ptr1 < size && ptr2 >= 0){
            if(height[ptr1] > left) left = height[ptr1];
            if(height[ptr2] > right) right = height[ptr2];
            maxLeft[ptr1] = left; 
            maxRight[ptr2] = right;
            ptr1++;
            ptr2--;
        }
        
        int water = 0;
        for(int x = 1; x < size - 1; x++){
            std::cout << maxLeft[x] << " " << maxRight[x] << " " << height[x] << "\n";
            water += std::min(maxLeft[x], maxRight[x]) - height[x];
        }
        return water;
    }
};