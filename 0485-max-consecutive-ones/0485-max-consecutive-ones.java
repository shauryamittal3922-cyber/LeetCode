class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int sum = 0;
        int max = 0;
        int i = 0;
        while(i < nums.length){
            if(nums[i] == 0){
                sum = 0;
            }
            sum += nums[i];
            i++;
            max = (max < sum)? sum : max;
        }
        return max;
    }
}