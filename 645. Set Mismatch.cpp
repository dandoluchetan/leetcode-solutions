/*You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

 

Example 1:

Input: nums = [1,2,2,4]
Output: [2,3]
Example 2:

Input: nums = [1,1]
Output: [1,2]
*/
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int rpt=0,miss=0,sum=0;
        for(int i=0; i<nums.size()-1;i++){
            if(nums[i]==nums[i+1] && rpt==0){
                rpt=nums[i];
            }
            sum=sum+nums[i];
        }//finding repeat no.
        sum=sum+nums[nums.size()-1];
        int real_sum=(nums.size()*(nums.size()+1))/2;
        miss=real_sum+rpt-sum;
        return {rpt,miss};
    }
};
