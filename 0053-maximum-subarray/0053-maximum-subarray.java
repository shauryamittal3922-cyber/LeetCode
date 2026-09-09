class Solution {
    public int maxSubArray(int[] nums) {
        int max = nums[0];
        int curr = nums[0];

        for(int i = 1; i < nums.length; i++){
            curr = (nums[i] > curr + nums[i])? nums[i] : curr + nums[i];

            if(max < curr) max = curr;
        }
        return max;
    }
}