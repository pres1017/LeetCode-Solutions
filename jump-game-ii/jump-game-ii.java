class Solution {
    /*
        THE PLAN:
            0.) CAN brute force by starting at the beginning, iterating through each jump and just saving the shortest (not viable due to large input)
            1.) Greedy Algorithm
            Pseudo Code:
                have pointer to current value
                while(pointer < sizeOfArr):
                    maxPossibleJump = 1
                    for(possible jumps):
                        if(new possible jump point > old max possible jump points) maxPossibleJump = new jump point # discount 0
                    pointer = pointer + maxPossibleJump
                    
    */
    public int jump(int[] nums) {
        int jumps = 0, currentJumpEnd = 0, farthest = 0;
        for(int i = 0; i < nums.length - 1; i++){
            farthest = Math.max(farthest, i + nums[i]);
            if(i == currentJumpEnd){
                jumps++;
                currentJumpEnd = farthest;
            }
        }
        return jumps;
    }
}