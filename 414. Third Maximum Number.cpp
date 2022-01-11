/*
Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.

Example 1:

Input: nums = [3,2,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2.
The third distinct maximum is 1.
Example 2:

Input: nums = [1,2]
Output: 2
Explanation:
The first distinct maximum is 2.
The second distinct maximum is 1.
The third distinct maximum does not exist, so the maximum (2) is returned instead.
Example 3:

Input: nums = [2,2,3,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2 (both 2's are counted together since they have the same value).
The third distinct maximum is 1.
*/
class Solution {
public:
    int thirdMax(vector<int>& nums) {
      //o(n)
        int max3,max2;
        int max1=max2=max3=nums[0];
       for(int i=1;i<nums.size();i++){
           if(nums[i]>max1){
               max3=max2;
               max2=max1;
               max1=nums[i];
           }
           else if(nums[i]<max1){
               if(max1==max2){
                   max2=nums[i];
                   max3=max2;
               }
               if(nums[i]>max2){
                   max3=max2;
                   max2=nums[i];
               }
               else if(nums[i]<max2)
               {
                   if(max2==max3)
                       max3=nums[i];
                   if (nums[i]>max3)
                       max3=nums[i];
               }
           }
       }
        if(max2==max3)
        return max1;
        else
            return max3;
    }
};
