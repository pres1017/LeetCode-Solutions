class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        toReturn = []
        for x in range(0, len(nums)):
            ptr1 = x + 1
            ptr2 = len(nums) - 1
            while(ptr1 < ptr2):
                potTarget = nums[x] + nums[ptr1] + nums[ptr2]
                if(potTarget < 0):
                    ptr1 += 1
                elif(potTarget == 0):
                    if [nums[x], nums[ptr1], nums[ptr2]] not in toReturn:
                        toReturn.append([nums[x], nums[ptr1], nums[ptr2]])
                    ptr1 += 1
                else:
                    ptr2 -= 1
        return toReturn
                    
        