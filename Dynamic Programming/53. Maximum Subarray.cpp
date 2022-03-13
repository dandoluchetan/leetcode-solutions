class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=nums[0],currentSum=nums[0];
        for(int i=1;i<nums.size();i++){
            currentSum=(nums[i]>nums[i]+currentSum)?(nums[i]):(nums[i]+currentSum);
            maxSum=maxSum>currentSum?maxSum:currentSum;
        }
        return maxSum;
    }
};
